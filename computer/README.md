计算机是由硬件子系统与软件子系统组成复杂系统。在软件子系统中，有一部分是引导计算机进入操作系统的程
序，一般将这类程序称为引导程序或固件；还有一部分是对计算机的硬件资源进行抽象并管理的程序，这类软件
组成的系统称为操作系统(OS, Operating System)；基于操作系统运行的、为用户提供服务的程序称为应用
程序。在硬件子系统中，一般有主板、cpu、内存、外存、键盘、显示器、网卡、显卡、声卡、机箱等设备。

硬件子系统
========

在现在的计算机市场中，根据不同的使用场景，计算机的配置也各不相同。例如通常场景中的台式电脑与笔记本
电脑、提供网络的的服务器设备、路由器、网关、防火墙等。这些计算机一般都会支持主板、cpu、内存、外存
、键盘、显示器、网卡、显卡、机箱、蓝牙适配器等，但是在不用场景中会省略一些设备来节约设备的成本。

主板
---

主板(main-board)是计算机的基础，其他设备需要通过主板上的预留的接口来接入主板，这些设备也是通过主板连接到cpu的。


CPU
---

cpu(Central Processing Unit)是计算机的核心，是实际执行任务的单元。，是信息处理，程序运行的最终执行单元；CPU包括控制器与运算器，CPU的性能指标有主频（时钟频率）、CPU位数、CPU缓存指令集、CPU核数、IPC
* 主频（时钟周期）直接决定CPU性能，可以通过超频技术来提高CPU的主频。

* CPU位数是指一次性计算的浮点位数

内存
----

内存(internal storage)就是所谓的内存条，所有的程序在运行时需要加载到内存中。内存具有掉电丢失的特性。所以需要将数据保存在外存上来保存数据。


外存
----

外存(external storage)就是软盘、固态硬盘、机械硬盘等掉电不丢失数据的存储设备。其读写速度比内存慢。


### Power
### Displayer
### Keyboard
###  Loudspeaker
### Network Card
### Graphics Card
### Sound Card
### Heat Sink

引导程序
=======

### BIOS
基本输入输出系统（BIOS, Bsic Input Output System）是在IBM PC兼容计算机上的引导过程的固件，是开机的第一个软件。用于加载操作系统。

#### legacy BIOS

legacy BIOS是传统的BIOS，与MBR分区共同使用 

#### UEFI BIOS

 Unified Extensible Firmware Interface是一种现代BIOS,与GPT格式分区共同使用。


### Boot Loader

Boot Loader是用于加载应用程序的固件。

#### U-BOOT

Universal Boot Loader是一个用于嵌入式系统的引导加载程序

#### GRUB

GrandUnified Boot Loader是引导内核加载程序，多用于Linux加载。


操作系统
=======

OS是将计算机硬件进行抽象和封装，并对应用软件提供一个统一接口的软件系统。OS将所有的I/O设备抽象为文
件，并提供文件操作接口；之后将文件与主存抽象为虚拟内存，最后将虚拟内存与CPU抽象为进程，为运行的程序
提供所有的计算机资源。

### GNU/Linux

### Windows

### MacOS

### Harmony

### Android

### iOS

---

应用软件
=======

### 计算机组成原理

* 计算机启动过程：整个计算机的启动阶段分为四个部分。

  * BIOS（Basic Input/Output System）存储计算机的开机程序，主要完成硬件自检、启动顺序选择。

    1. POST（Power-On Self-Test）：BIOS通过读取CMOS中的内容来识别硬件配置，并对其进行自检和初始化；并装载引导程序和与I/O驱动程序以及终端
       服务。

    2. Boot Sequence：BIOS将系统的控制权交给真正的启动程序。

  * MBR（Master Boot Record）：主引导记录由512Byte组成；其中1~446Byte是调用操作系统的机器码，447~510Byte是分区表，511-522Byte为主引导
    记录签名。其中分区表长64Byte，又分为4个主分区，每一个主分区16个字节；第1Byte为`0X80`时标志为激活分区，2~4Byte为第一个扇区的物理位置，
    5Byte为主分区类型，6~8Byte主分区最后一个扇区位置，9~12Byte主分区第一扇区的逻辑地址，13~16Byte为主分区的扇区总数。

  * VBR（Volume Boot Record）：卷引导记录是激活分区的第一个扇区，存储操作系统在该分区的物理地址。将扩展分区的第一个扇区称为EBR（Extended
  Boot Reoerd）。或者由MBR直接到启动管理器。例如Grub。

  * OS（Operating System）：由启动管理器或者主引导记录直接进入操作系统。


### 计算机网络通信

### 计算机系统安全


## 基本简述

* Amdahl定律：当我们对系统中的某一部分进行加速时，其对于整个系统的影响取决于该部分在系统的占比与加速程度：

$$
  描述：对需要消耗T时间的系统，对其中一部分T_1加速了m倍，则对整体系统的加速为多少？\\
  解：令\alpha = \frac{T_1}{T}，则有加速后系统所需时间：T_{new} = (1-\alpha)T + mT_1；  \\
  则系统整体加速比：S = \frac{T}{T_{new}} = \frac{1}{(1-\alpha) + m\alpha}.
$$

## 计算机病毒

* 文件型病毒
* 变型病毒
* 开机型病毒
* 复合型病毒
* 复制型病毒
* 宏病毒
* 练习型病毒

黑客类型：

* 好奇型
* 恶作剧型
* 隐秘型
* 定时炸弹型
* 重旁炸弹型





## 文件

文件就是字节序列，OS将所有I/O设备当作一个文件，并提供I/O访问接口。

## 虚拟内存

虚拟内存是对主存与所有I/O设备的抽象，为进程提供一个独占主存的假象。每一个进程看到的都是一样的虚拟地址空间，分别是（地址由低到高）：只读的代码和数据、可读写的数据、运行时堆（由低到高分配）、共享库的映射区域、用户栈（由高到低分配）、内核虚拟内存。

## 进程

进程是对CPU与虚拟内存的封装，是对运行时程序的抽象

## 线程


## 超线程

超线程又称为同时多线程，是将CPU中的PC和寄存器文件有多的技术，是一个核可以执行多个线程的技术

## 并行

并行是指适用并发来使系统运行的更快

## 并发






## 接口标准

总线PCI

接口SCSI、IDE
---

## 资源链接


在计算机上电之后，电路启动自检工作，将所有的寄存器全部重置，如果哪里出现异常，就记录到EAX寄存器中。

一般CPU都工作在保护模式下，使用虚拟地址来访问内存，虚拟内由MMU负责转化为物理地址，在计算机刚上电时，页目录与页表信息不存在，MMU无法工作，此时是工作在实地址模式，只能使用16位寄存器使用段加基址的方式来访问内存，最多使用1MiB的内存空间。

在所有设备复位后，CPU以CS:IP(0xF000:0xFFF0)来访问BIOS,对主板上的各单位进行检测等工作。（此时只有引导处理器BSP在工作，其他核不工作）；在检测通过后，根据BIOS中的启动顺序，读取硬盘的第0盘第0道第1扇区到0x7C00的位置（主引导记录MBR），并随后执行0x7c00上的程序，此时需要切换工作模式，启动MMU,之后为其他核准备数据，



# 信息的表示与存储

在计算机中，所有的信息都是以二进制的形式表示、处理、存储与传输的；十进制是人类日常生活所使用的数据表示方式。在信息的存储中，每一个二进制被称作位，单位位bit；而每一个数据都是以8bit的位向量的形式进行存储的，将其称为字节，单位位Byte。为了更好的表达数据，引入了十六进制来表示数据。

## 数据的表示

数据是计算机处理的对象，也是描述客观事物的抽象模型。在数据的表示中我们需要了解进制的表示及其转化、不同数据类型的表示形式和处理方法。

### 进制表示

二进制是以2为基数的数据表示方式，也是计算机表示、处理、存储与传输的方式；十进制是以10为基数的数据表示方式，是人类习惯使用的数据表示方式；十六进制是以16为基数的数据表示方式，是人类理解二进制数据另一种表示方式。

二进制

十进制

十六进制

### 数据类型的表示

数据的的表示有数字与字符两种形式，需要根据不同的编码方式来表示。

#### 数字类型

数值类型的数据可以分为无符号整型、有符号整型与浮点型三大类。其中无符号整型与有符号整型属于精确表示，浮点数属于近似表示。数字的二进制编码规则有原码、反码以及补码；原码是直接将数据转化为二进制的表示方式，反码是将数据的二进制原码进行取反（除符号位之外），补码是在反码的基础上加1。

* 无符号整型：无符号整型只能表示大于等于0的整数，通常是使用原码的编码方式来表示数据的。
* 有符号整型：有符号整型可以表示负整数、正整数与0，通常使用补码的编码方式来表示数据的。
* 浮点数：浮点数是近似表示极大与极小数字以及小数，通常有单精度与双精度两种。

在 <limits.h>中定义了每组类型的范围。在<stdint.h>

#### 字符类型


## 数据的存储

数据的存储是以字节为单位进行存储的，字节是以8位二进制组成的位向量，是计算机寻址的最小单位，具有唯一的地址编码；在32位与64位计算机中，地址具有不同的大小，将计算机中地址的标称大小称为字长，例如，32位计算机中的字长是4B，64位计算机中的字长8B。同时，数据的存储有单字节与多字节之分，在多字节数据的存储中，数据的地址是连续多字节地址中最小的地址，并且根据存储顺序的不同分为大端法与小端法，大端法是数据的最高字节存储在最小地址的字节中，小端法是最低字节存储在最小地址的字节中。

大多数Intel兼容机采用的都是小端模式，IBM与Oracle的多数机器采用大端模式，较新的微处理器采用双端模式，例如ARM微处理器，双端模式是由操作系统来决定的，例如采用ARM平台的Android与IOS只能运行小端模式。    


-------------------
2022-04-16




u-boot经过编译后直接生成ELF格式的可执行程序u-boot， 该程序经过objcopy工具进行加工得到u-boot.bin
该镜像文件才是我们需要烧录到设备中的文件。

linux kernel经过编译后会生成一个ELF格式的问可执行程序vmlinux或者vmlinuz，这是原始内核的ELF文件。
在经过objcopy处理之后称为Image镜像文件；该文件在经过压缩之后成zImage文件，在经过uboot中的mkimage
工具生成uImage用于u-boot启动的镜像格式有vmlinuz、zImage与uImage三种格式。




### 文件系统

文件是Linux中基础，具有所有者、所属组、权限、时间（mtime、ctime、atime）等属性；FS（File System，文件系统）是一个由文件组成的系统。Linux中
的FS是以树状结构的形式存在，起点为根目录`/`，每一个目录节点提供归属关系：CD（Child Directory，子目录）与PD（Parent Directory，父目录）；
且由根目录开始的所有途径的目录名和文件名组成该文件的绝对目录，从工作目录开始的所有途径的目录名与文件名组成该文件的相对目录。工作目录是Linux中的
一个变量，表示shell程序当前的工作目录，可以由`pwd`来获取或使用`cd`修改其值。在Linux中，目录是一种特殊的文件，其中`.`表示当前目录，`..`表示父
目录。当FS中新建一个文件时，会在工作目录建立一个指向该文件的HL（Hard Link，硬链接）；文件有HL才会被纳入FS，否则会被删除；而文件的硬链接数目
LC（Link Count，链接数）可以有多个，可以使用`ln`创建和`unlink`删除HL；为保持FS的树状结构，Linux系统推荐使用SL（Soft Link，软链接），新建
SL不会影响LC，其实质是`symbolic link`文件，包含有链接指向文件的绝对路径。编辑文件时，Linux只会将内容的编辑导向SL指向的文件，类似于Windows
的快捷方式，使用`ln -s`创建SL。可以使用`file`来查询文件的类型。





----------------
虚拟网络设备

TUN与TAP是操作系统内核中的虚拟网络设备，该设备是由软件实现，并向运行于操作系统上的软件系统与硬件网络设备同样的功能。TAP等同于一个以太网设备，用于操作
链路层的数据；TUN模拟了网络层设备，操作网络层数据。

虚拟网卡实现内核协议栈与用户空间的程序之间传递数据。


DMA与CPU
