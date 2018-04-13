#include<linux/init.h>
#include<linux/module.h>
#include<linux/cdev.h>
#include<linux/fs.h>
#include<linux/slab.h>
#include<linux/uaccess.h>

#define DNAME "my_dev"
#define MAJORNO 90
#define MINORNO 0

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Demo Driver");
MODULE_AUTHOR("Vinay");

unsigned int SIZE = 1024;
static char *d_buff = NULL;
static int times = 0;
int inuse = 1;
dev_t mydev;
struct cdev *my_cdev;
struct class *my_class;
static int dev_open(struct inode *, struct file *);
static int dev_close(struct inode *, struct file *);
static ssize_t dev_read(struct file *, char *, size_t, loff_t *);
static ssize_t dev_write(struct file *, const  char *, size_t, loff_t *);
static loff_t dev_lseek (struct file *, loff_t, int);
static struct file_operations fops = {
	.read = dev_read,
	.write = dev_write,
	.open = dev_open,
	.release = dev_close,
	.llseek = dev_lseek
};

static loff_t dev_lseek(struct file *fp, loff_t  offset, int flag){
	loff_t newpos;
	switch(flag){
		case 0:		/* SEEK_SET */
			newpos = offset;
			break;

		case 1:		/* SEEK_CUR */
			newpos = offset + fp->f_pos;
			break;

		case 3:		/* SEEK_END */
			newpos = SIZE + offset; 
			break;
		default:
			return -EINVAL;
	}
	if(newpos >= SIZE){
		printk(KERN_ERR"No Space for lseek()");
return -EINVAL;
}
fp->f_pos = newpos;
	printk(KERN_INFO"lseek() success new offset:%d\n", (int)newpos);
	return newpos;
}

static ssize_t dev_read(struct file *fp, char *u_buff, size_t len, loff_t *offset){
	int nbyte, mbyte, abyte;
	printk(KERN_INFO"Device read() called with len:%d offset:%d\n", (int)len, (int)*offset);
	mbyte = SIZE - *offset;
	if(mbyte > len) abyte = len;
	else abyte = mbyte;
	if(abyte == 0){
	printk(KERN_ERR"No Space left for read..");
	return -ENOSPC;
	}

	nbyte = abyte - copy_to_user( u_buff,d_buff + *offset , abyte);
	*offset += nbyte;
	printk(KERN_INFO"Device Read Complete new offset is: %d",(int)*offset);
	return nbyte;
}

static ssize_t dev_write(struct file *fp, const char *u_buff, size_t len, loff_t *offset){
	int nbyte, mbyte, abyte;
	printk(KERN_INFO"Device write() called with  len:%d offset:%d\n", (int)len, (int)*offset);
	mbyte = SIZE - *offset;
	if(mbyte > len) abyte = len;
	else abyte = mbyte;
	if(abyte == 0){
	printk(KERN_ERR"No Space left for write..");
	return -ENOSPC;
	}

	nbyte = abyte - copy_from_user( d_buff + *offset, u_buff, abyte );	
	printk(KERN_INFO"copy_from_user() complete  data size: %d data : %s\n", (int)len, d_buff);
	*offset += nbyte;
	printk(KERN_INFO"Device Write Complete new offset is: %d\n",(int)*offset);
	return nbyte;
}

int init_module(void){
	int ret;

	if((d_buff = (char *)kmalloc(SIZE*sizeof(char),GFP_KERNEL))==NULL){
		printk(KERN_ERR"kmalloc failed ..");
	return -1;
	}
	memset(d_buff,0,SIZE);
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
		unregister_chrdev_region(mydev, 1);
		kfree(d_buff);
	return ret;
	}
	my_class = class_create(THIS_MODULE, "MY_TEMP");
	device_create(my_class, NULL, mydev, NULL, "%s", "myDev");
	printk(KERN_INFO"Device Registration Success...\n");
	printk(KERN_INFO"Major No: %d Minor No: %d\n", MAJOR(mydev), MINOR(mydev));
	return ret;
}

void cleanup_module(void){
/*
int i;
for(i=0;i<512;i++){
if(d_buff[i] != NULL)
printk(KERN_CONT"Buff[%d]:%c ",i,d_buff[i]);
}
printk(KERN_CONT"Done..");*/
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

