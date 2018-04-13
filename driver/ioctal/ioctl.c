#include<linux/init.h>
#include<linux/module.h>
#include<linux/cdev.h>
#include<linux/fs.h>
#include<linux/uaccess.h>
#include<linux/slab.h>
#include "ioctl_h.h"

#define DNAME "my_dev"
#define MAJORNO 90
#define MINORNO 0

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Demo Driver");
MODULE_AUTHOR("Vinay");

static char *d_buff = NULL;
static int times = 0;
int inuse = 1;
static int SIZE = 1024;
dev_t mydev;
struct cdev *my_cdev;
struct class *my_class;
static int dev_open(struct inode *, struct file *);
static int dev_close(struct inode *, struct file *);
static ssize_t dev_read(struct file *, char *, size_t, loff_t *);
static ssize_t dev_write(struct file *, const  char *, size_t, loff_t *);
static long dev_ioctl(struct file *, unsigned int, unsigned long ); 
//static long dev_ioctl(struct inode *, struct file *, unsigned int, unsigned long ); 

static struct file_operations fops = {
	.read = dev_read,
	.write = dev_write,
	.open = dev_open,
	.release = dev_close,
	.unlocked_ioctl = dev_ioctl
};

//static long dev_ioctl(struct inode *inod, struct file *fp, unsigned int cmd, unsigned long arg){
static long dev_ioctl(struct file *fp, unsigned int cmd, unsigned long arg){
	unsigned int  size;
	char *new_buff = NULL;
	char ch;
	if(_IOC_TYPE(cmd) != MY_MAGIC) return -ENOTTY;
	if(_IOC_NR(cmd) > MAX_CMDS) return -ENOTTY;

	if(_IOC_DIR(cmd) & _IOC_READ)
		if( !access_ok(VERIFY_WRITE, (void *)arg, _IOC_SIZE(cmd)))
			return -EFAULT;

	if(_IOC_DIR(cmd) & _IOC_WRITE)
		if( !access_ok(VERIFY_READ, (void *)arg, _IOC_SIZE(cmd)))
			return -EFAULT;

	switch(cmd){
		case FILL_ZERO:
			memset(d_buff, 0, SIZE);
			break;

		case FILL_CHAR:
			copy_from_user(&ch,(char *)arg, sizeof(char)); 
			memset(d_buff, ch, SIZE);
			break;

		case SET_SIZE:
			copy_from_user(&size,(unsigned int *)arg, sizeof(unsigned int)); 
			new_buff =(char*) kmalloc(size*sizeof(char),GFP_KERNEL);
			if(!new_buff)
				return -ENOSPC;
			kfree(d_buff);
			d_buff = new_buff;
			fp->f_pos = 0;

			memset(d_buff, 0, SIZE);
			SIZE = size;
			break;

		case GET_SIZE:
			size = SIZE;
			copy_to_user((unsigned int *)arg, &size, sizeof(unsigned int));
			break;

	}
	return 0;
};

static ssize_t dev_read(struct file *fp, char *buff, size_t len, loff_t *off){
	printk(KERN_INFO"Device read() called with len:%d offset:%d\n", (int)len, (int)*off);
	copy_to_user( buff,d_buff, len);
	*off += len;
	printk(KERN_INFO"Device Read Complete new offset is: %d",(int)*off);
	return len;
}

static ssize_t dev_write(struct file *fp, const char *buff, size_t len, loff_t *off){
	printk(KERN_INFO"Device write() called with  len:%d offset:%d\n", (int)len, (int)*off);
	copy_from_user( d_buff, buff, len );	
	printk(KERN_INFO"copy_from_user() complete  data size: %d data : %s\n", (int)len, d_buff);
	*off += len;
	printk(KERN_INFO"Device Write Complete new offset is: %d\n",(int)*off);
	return len;
}


int init_module(void){
	int ret;

	d_buff = kmalloc(SIZE *(sizeof (char)), GFP_KERNEL);
	if (!d_buff){	
		printk(KERN_ERR"Device Registration Fialed kmalloc() failed.\n");

	}
	if(alloc_chrdev_region(&mydev, 0, 1, DNAME) < 0){
		printk(KERN_ERR"Failed to reserve major/minor number...");
		kfree(d_buff);
		return -1;
	}
	if(!(my_cdev = cdev_alloc())){
		printk(KERN_ERR"cdev_alloc() Filed...\n");
		unregister_chrdev_region(mydev, 1);
		kfree(d_buff);
		return -1;
	}
	cdev_init(my_cdev, &fops);
	ret = cdev_add(my_cdev, mydev, 1);
	if(ret < 0){
		printk(KERN_INFO"Device Registration Fialed...\n");
		cdev_del(my_cdev);
		kfree(d_buff);
		unregister_chrdev_region(mydev, 1);
		return ret;
	}

	my_class = class_create(THIS_MODULE, "MY_TEMP");
	device_create(my_class, NULL, mydev, NULL, "%s", "myDev");

	printk(KERN_INFO"Device Registration Success...\n");
	printk(KERN_INFO"Major No: %d Minor No: %d\n", MAJOR(mydev), MINOR(mydev));
	return ret;
}

void cleanup_module(void){
	device_destroy(my_class, mydev);
	class_destroy(my_class);
	cdev_del(my_cdev);
	unregister_chrdev_region(mydev, 1);
	kfree(d_buff);
	printk(KERN_INFO"Device Removed Successfuly...\n");
}

static int dev_open(struct inode *inod, struct file *fil){
	if(inuse){
		times++;
		printk(KERN_INFO"Device Opened %d Times\n",times);
		inuse = 0;
		return 0;
	}
	else{
		printk(KERN_ERR"Unable to open device Inuse\n");
		return -1;
	}
}

static int dev_close(struct inode *inod, struct file *fil){
	printk(KERN_INFO"Device Closed...\n");
	inuse = 1;
	return 0;
}

