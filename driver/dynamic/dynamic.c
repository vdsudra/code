#include<linux/init.h>
#include<linux/module.h>
#include<linux/cdev.h>
#include<linux/fs.h>
#include<linux/uaccess.h>

#define DNAME "my_dev"
#define SIZE 1024
#define MAJORNO 90
#define MINORNO 0

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Demo Driver");
MODULE_AUTHOR("Vinay");

static char d_buff[SIZE] = {0};
static int times = 0;
int inuse = 1;
dev_t mydev;
struct cdev *my_cdev;
static int dev_open(struct inode *, struct file *);
static int dev_close(struct inode *, struct file *);
static ssize_t dev_read(struct file *, char *, size_t, loff_t *);
static ssize_t dev_write(struct file *, const  char *, size_t, loff_t *);

static struct file_operations fops = {
	.read = dev_read,
	.write = dev_write,
	.open = dev_open,
	.release = dev_close,
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
	if(alloc_chrdev_region(&mydev, 0, 1, DNAME) < 0){
		printk(KERN_ERR"Failed to reserve major/minor number...");
		return -1;
	}
	if(!(my_cdev = cdev_alloc())){
		printk(KERN_ERR"cdev_alloc() Filed...\n");
		unregister_chrdev_region(mydev, 1);
	return -1;
	}
	cdev_init(my_cdev, &fops);
	ret = cdev_add(my_cdev, mydev, 1);
	if(ret < 0){
		printk(KERN_INFO"Device Registration Fialed...\n");
		unregister_chrdev_region(mydev, 1);
		return ret;
	}
		printk(KERN_INFO"Device Registration Success...\n");
		printk(KERN_INFO"Major No: %d Minor No: %d\n", MAJOR(mydev), MINOR(mydev));
	return ret;
}

void cleanup_module(void){
	cdev_del(my_cdev);
	unregister_chrdev_region(mydev, 1);
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

