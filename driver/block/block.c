#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>
#include <linux/kernel.h> 
#include <linux/fs.h>     
#include <linux/errno.h> 
#include <linux/types.h>
#include <linux/vmalloc.h>
#include <linux/genhd.h>
#include <linux/blkdev.h>
#include <linux/hdreg.h>
#include<linux/cdev.h>
#include<linux/uaccess.h>

#define DNAME "my_dev"
#define SIZE 1024

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Demo Driver");
MODULE_AUTHOR("Vinay");

int inuse = 1;
static int times = 0;

static int sector_size = 512;
module_param(sector_size, int, 0);

static int sector_nos = 1024;
module_param(sector_nos, int, 0);

struct block_device{
unsigned long size;
spinlock_t lock;
u8 * data;
struct gendisk *gd;
} Device;

#define KERNEL_SECTOR_SIZE 512
static void block_req( struct request_queue *q);

static int block_open(struct block_device *bd, fmode_t pos){
return 0;
}

static struct block_device_operations fops = {
	.open = block_open
};



dev_t mydev;


struct cdev *my_cdev;
struct class *my_class;
static int dev_open(struct inode *, struct file *);
static int dev_close(struct inode *, struct file *);
static ssize_t dev_read(struct file *, char *, size_t, loff_t *);
static ssize_t dev_write(struct file *, const  char *, size_t, loff_t *);

static void block_req( struct request_queue *q){
	struct request_queue *req;
	while(req = blk_fetch_request(q) != NULL){
		if(!blk_fs_request(req)){
			__blk_end_request(req, 0, 0);
			continue;
		}
		do_actual_req(req);
	}
}

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


int init_block(void){
	int ret;
	Device.size = sector_size * sector_nos;
	spin_lock_init(&Device.lock);
	Device.data=vmalloc(Device.size);
	if(Device.data == NULL){
		printk(KERN_ERR"vmalloc() failed to allocate memory..");
		return -1;
	}

	memset(Device.data, 0, Device.size);

	Queue = blk_init_queue(block_req, &Device.lock);
	if(Queue == NULL)
	return -1;
blk_queue_logical_block_size(Queue, sector_size);


	major = register_blkdev(major, "xx0");
	if(major <= 0){
		printk(KERN_ERR"Unable to get major number");
		return -1;
	}

	mydev = MKDEV(major, 0);

	if(!(my_cdev = cdev_alloc())){
		printk(KERN_ERR"cdev_alloc() Filed...\n");
		unregister_chrdev_region(mydev, 1);
	return -1;
	}
	cdev_init(my_cdev, &fops);
	ret = cdev_add(my_cdev, mydev, 1);
	my_class = class_create(THIS_MODULE, "MY_TEMP");
	if(IS_ERR(my_class)){
		printk(KERN_ERR"class_create() Filed...\n");
	return -1;
	}

	dev = device_create(my_class, NULL, mydev, NULL, "xx0");
	Device.gd = alloc_disk(1);
	if(!Device.gd){
	//do unre
	return -1;
	}
	Device.gd->major = major;
	Device.gd->first_minor = 0;
	Device.gd->fops = &bops;
	Device.gd->private_data = &Device;
	strcpy(Device.gd->disk_name, "xx0");
	set_capacity(Device.gd, sector_nos * (sector_size/KERNEL_SECTOR_SIZE));
	add_disk(Device.gd);
	return 0;



	if(ret < 0){
		printk(KERN_INFO"Device Registration Fialed...\n");
		cdev_del(my_cdev);
		unregister_chrdev_region(mydev, 1);
		return ret;
	}

		printk(KERN_INFO"Device Registration Success...\n");
		printk(KERN_INFO"Major No: %d Minor No: %d\n", MAJOR(mydev), MINOR(mydev));
	return ret;
}

void cleanup_module(void){
device_destroy(my_class, mydev);
class_destroy(my_class);
	cdev_del(my_cdev);
	unregister_chrdev_region(mydev, 1);
	printk(KERN_INFO"Device Removed Successfuly...\n");
}

