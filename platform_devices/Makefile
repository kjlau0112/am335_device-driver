obj-m := pcd_devices_setup.o
ARCH=arm
CROSS_COMPILE=arm-linux-gnueabihf-
#set KERN_DIR to linux source location 
KERN_DIR = ~/workspace/ldd/source/linux/
HOST_KERN_DIR = /lib/modules/$(shell uname -r)/build/
PWD= /home/kj/beagleboneKernelCode/platform_devices/

all:
	make ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) -C $(KERN_DIR) M=$(PWD) modules
clean:
	# make -C $(HOST_KERN_DIR) M=$(PWD) clean
	make ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) -C $(KERN_DIR) M=$(PWD) clean
help:
	make ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) -C $(KERN_DIR) M=$(PWD) help
host:
	make -C $(HOST_KERN_DIR) M=$(PWD) modules

#sudo make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -C /home/kj/workspace/ldd/source/linux/ M=$PWD clean
#sudo make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -C /home/kj/workspace/ldd/source/linux/ M=$PWD modules
#sudo make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -C /lib/modules/4.14.108/build M=$PWD modules
