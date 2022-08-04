cryptodev-linux是linux kernel的一个独立模块。

该模块通过实现cryptodev来允许用户访问内核的加密模块，cryptodev是一个允许访问linux kernel加密
驱动程序的设备，可以实现允许用户空间利用硬件加速。

该模块的API兼容OpenBSD的cryptodev（/dev/crypto）用户空间的API。
