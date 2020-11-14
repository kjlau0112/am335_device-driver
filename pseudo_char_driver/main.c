#include <linux/module.h>
#include <linux/cdev.h>
#include <linux/fs.h>

#define DEV_MEM_SIZE 512

/* pseudo device's memory */
char device_buffer[DEV_MEM_SIZE];

/* This holds the device number */
dev_t device_number;


/* Cdev variable */
struct cdev pcd_cdev;

loff_t pcd_lseek(struct file *filp, loff_t offset, int whence)
{
	return 0;
}

ssize_t pcd_read(struct file *filp, char __user *buff, size_t count, loff_t *f_pos)
{
	return 0;
}


ssize_t pcd_write(struct file *filp, const char __user *buff, size_t count, loff_t *f_pos)
{
	return 0;
}

int pcd_open(struct inode *inode, struct file *filp)
{
	return 0;
}

int pcd_release(struct inode *inode, struct file *flip)
{
	return 0;
}

/* file operations of the driver */
struct file_operations pcd_fops=
{
	.open = pcd_open,
	.release = pcd_release,
	.read = pcd_read,
	.write = pcd_write,
	.llsek = pcd_lseek,
	.owner = THIS_MODULE
}; 
static int __init  pcd_driver_init(void)
{
    int ret;

	/*1. Dynamically allocate a device number */
	ret = alloc_chrdev_region(&device_number,0,1,"pcd_devices"); // 1 device only
	
	if(ret < 0)
    {
		pr_err("Alloc chrdev failed\n");
	//	goto out;
	}
    pr_info("Device number <major>:<minor> = %d:%d\n",MAJOR(device_number),MINOR(device_number));

	/*2. initialize the dev structure with pcd file operations*/
	cdev_init(&pcd_cdev,&pcd_fops);

	/*3. register pcd driver with virtual file system.*/
	pcd_cdev.owner = THIS_MODULE;

	ret = cdev_add(&pcd_cdev,device_number,1);  // 1 device only
	
	if(ret < 0){
		pr_err("Cdev add failed\n");
		//goto unreg_chrdev;
	}


    return 0;
}

static void __exit pcd_driver_exit(void)
{
    pr_info("goodbye world\n");
}

module_init(pcd_driver_init);
module_exit(pcd_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("KJ");
MODULE_DESCRIPTION("BBB kernel module");
MODULE_INFO(board,"beaglebone black");