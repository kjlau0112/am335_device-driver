#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/kdev_t.h>
#include <linux/uaccess.h>
#include "devices_info.h"

#undef pr_fmt
#define pr_fmt(fmt) "%s : " fmt, __func__

void pcdev_release(struct device *dev)
{
    pr_info("device release\n");
}

struct pcdev_platform_data pcd_devdata[2] =
{
    [0] = {.size =512,   .perm =RDWR, .serial_number="PCDEV111"},
    [1] = { .size =1024, .perm= RDWR, .serial_number="PCDEV222"}

};

/*create 2 platfor devices*/
struct platform_device platform_pcdev_1=
{
    .name ="pseduo-char-device",
    .id = 0,
    .dev = { .platform_data = &pcd_devdata[0], .release = pcdev_release }
};

struct platform_device platform_pcdev_2=
{
    .name ="pseduo-char-device",
    .id = 1,
    .dev = { .platform_data = &pcd_devdata[1]}
};

static int __init pcd_pltatform_init(void)
{
    platform_device_register(&platform_pcdev_1);
    platform_device_register(&platform_pcdev_2);
     
    return 0;
}

static void __exit pcd_pltatform_exit(void)
{
    platform_device_unregister(&platform_pcdev_1);
    platform_device_unregister(&platform_pcdev_2);
}

module_init(pcd_pltatform_init);
module_exit(pcd_pltatform_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Module which registers platform devices");