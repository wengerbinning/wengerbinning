bootloader是开机引导系统的一段固定程序，一般可以分为单阶段、多阶段。多阶段的bootloader可以提供
复杂的功能以及更好的可移植性。从固态存储设备上启动bootloader大多是两阶段启动，第一阶段使用汇编来
实现，第二阶段使用C语言实现。在第一阶段中，通常完成硬件设备的初始化：设置时钟、关闭看门狗与中断、启
动ICACHE、关闭DCACHE与TLB、关闭MMU、初始化内存空间、复制第二阶段代码到内存中。之后执行第二阶段的
引导程序。




Boot Loader可以有多个产品U-Boot、GRUB、NT loader、LILO、Yaboot.


U-Boot是一个主要用于嵌入式系统的引导加载程序，可以支持多种计算机系统结构，例如：x64、arm、mips、ppc、avr32、nios、microblaze与68k等。
U-Boot不仅可以支持引导嵌入式Linux，而且支持Android、NetBSD、Vxworks、QNX、RTEMS、ARTOS、LynxOS等.

GRUB是一个多操作系统的引导程序，允许计算机存在多个操作系统，

NT loader是Windows默认的引导程序。

LILO与GRUB类似。

Yaboot常见于MacOS等。

