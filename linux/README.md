Linux是由Linus Torvalds开发的内核与GNU项目的软件集组合成的一个开源操作系统，为向GNU组织致敬，
在网络上也会出现GNU/Linux来指这个开源操作系统。

Linux是由Linus Torvalds领导开发的系统内核，其目的是为计算机上其他程序分配计算机资源：CPU、
内存、外部设备等。在内核之上有一部分软件完成了计算机的日常维护，这一类软件称为系统软件，有内核与
系统软件共同组成操作系统。在系统软件中，大部分都是以客户端与服务器模型中的服务器的形式存在，这一类
服务有称为守护进程。

1983年，Richard Stallman宣布要开发GNU项目，在项目中将实现内核以及系统程序的在内的完成的
操作系统，该系统将与UNIX完全兼容，目的是为每一个人可以自由的使用与修改GNU项目中的自由软件。
在1991年，GNU项目除内核其他大部分的都已完成。

UNIX是需要现代化计算机工具辅助来完成项目的科研工作者开发的。该系统允许一组人协同工作。一些
大学与学院在UNIX发展中扮演着重要的角色。UNIX刚开始是以象征性的价格向大学开放，，后来UNIX被商业
化，不再适用于教学。

MINIX是Andrew Tanenbaum教授开发的用于教学的系统；Linus在MINIX的基础上开发了Linux。Linux
可以通过网络免费获取以及支付一定费用可以获取的GNU项目中的自由软件。这样促进了Linux与自由软件的结合。
现在称Linux更多的是指由各类组织提供的Linux发行版，例如Debian、CentOS、Arch、Ubuntu等，这是由
Linux内核与众多系统软件组成的操作系统。之后，我们也这样称呼，并将Linux kernel来特指指Linux的内核。

Linux与自由软件都是在GNU公共许可协议下(GNU GPL)发布的。Linux之所以大受欢迎，是因为其扩展性强、
可移植性强、拥有总多的技术爱好者共同开发，作为一款通用操作系统，有专用操作系统无法比拟的通用性及普遍性。

在计算机工业界，各家公司共同制定了可移植的操作系统接口(POSIX)标准。这一标准很大程度上是基于UNIX
SVID(System V Interface Definiitio)和其他标准化工作。

1969年，Ken Thompson用PDP-7汇编实现了UNIX操作系统，为使该操作系统具有可移植性，Thompson在
BCPL语言的基础上开发了与计算机无关的编程语言：B语言，Dennis Rithie通过修改B语言开发了C语言，并与
Thompson合作，使用C语言重构了UNIX。

20世纪80年代，美国国家标准协会(ANSI)定义了C语言的标准，被成为ANSI C或者C89标准；在1999年，
发布了C99标准。

贝尔实验室的研究员Bjarne Stroustrup在C语言的基础上开发了面向对象的的编程语言：C++。使得编程
更加高效。

Linux是一个支持内核编程接口、多用户、多任务以及安全的分层文件系统的操作系统

Linux内核版本有两种：稳定版与开发版，并通过版本的命名机制来区分：`主版本号.从版本号.修订版本号[·稳定版本号]`
当从版本号为偶数则为稳定版，否则为开发版

Linux操作系统是一种类UNIX操作系统.它诞生于1991年10月5日,是由Linus Torvalds开发的Linux Kernel与GNU计划中的自由软件结合的的类Unix操作系统.其具有多用户、多任务、多线程、支持所有的网络协力的特点;所以广泛运用服务器、程序开发、嵌入式等应用场景.Linux(GNU/Linux)是一套免费使用和自由传播的类UNIX操作系统,继承了Unix以网络为核心的设计思想;其内核由Linus Benedict Torvalds于1991年发布.由于Linux Kernel遵循POSIX标准,所以能运行主要的Unix工具软件、应用程序和网络协议;Linux有终端与界面两种管理方式，其中界面中的X-Windows是一个类Windows的操作界面,Linux支持多种硬件平台,广泛用于服务器与嵌入式;Linux有众多的发行版本,如Red Hat发行的`Red Hat Linux`,`Red Hat Enterprise`,`Redora`,`CentOS`;SUSE发行的`SUSE Linux Enterprise`,`openSUSE`;Debian发行的`Debian`,`Ubuntu`,`Mint`,`Gentoo`,`Arch Linux`,`Mandriva`,`Slackware`,`TurboLinux`。

## 资源连接

> [官方网站](https://www.linux.org/) ☛ <https://www.linux.org/>

* [Linux入门教程](https://www.linux.org/forums/linux-beginner-tutorials.123/) ☛ <https://www.linux.org/forums/linux-beginner-tutorials.123/>

  1. [Linux简介](https://www.linux.org/threads/what-is-linux.4106/) ☛ <https://www.linux.org/threads/what-is-linux.4106/>
  2. [Linux的安装方式](https://www.linux.org/threads/what-type-of-installation-should-i-do-dual-boot-live-cd-fresh-install-virtual-installation.4116/) ☛ <https://www.linux.org/threads/what-type-of-installation-should-i-do-dual-boot-live-cd-fresh-install-virtual-installation.4116/>
  3. [Debian安装](https://www.linux.org/threads/installing-debian.4118/) ☛ <https://www.linux.org/threads/installing-debian.4118/>

## 基础知识

### 程序


环境变量是操作系统中用来指定操作系统运行时的环境参数，环境变量通常以键值对存储。类似于命令参数，存储在用户空间。

* `PATH`：可执行文件的搜索路径。
* `SHELL`：当前shell程序。
* `TERM`：当前终端类型，决定一些程序的显示方式。
* `LANG`：语言和locale。
* `HOME`：当前用户的家目录。

在`stblib.h`中定义了管理环境变量的函数。

* `getenv()`
* `setenv()`
* `unsetenv()`

在`unistd.h`中定义了创建子进程的函数。

* `fork()`:

## 发展简述

### Debian

Debian是由Ian Murdock与1993年发布的,基于Debian的桌面环境有Ubuntu(根据桌面可分为基于GNOME的Ubuntu、基于KDE的KUbuntu、基于Xface的XUbuntu)，二Mint是基于Debian与Ubuntu发行的.

### Red Hat

Red Hat由Marc Ewing发布的Linux发行版本,目前Red Hat有RHEL(Red Hat Enterprise Linux,提供收费技术支持与更新)、Fedora是Red Hat的技术实验平台、CentOS.

### Gentoo

Gentoo是Linux最年轻的发行版本.

### Mandriva

### CtenOS

* CentOS是一个开源的Linux操作系统,官方提供两种发行版本,分别为CentOS Linux与CentOS Stream;

* [官方网站](https://www.centos.org/) > https://www.centos.org
  1. [官方介绍](https://www.centos.org/about/) > https://www.centos.org/about/
  2. [官方文档](https://) > https://
  3. [官方社区]() > 

### Ubuntu

在Linux系统启动之后,Linux的内核程序启动称为一个单一的内核进程,该进程有权调用计算机的所有资源.当应用程序启动时,内核会分配一定的计算机资源.应用程序与硬件之间的互动,也必须经过内核进行.我们将内核程序的活动称为**内核模式**,而将应用程序的活动称为**用户模式**.应用程序可以通过特定的接口来调用内核功能.用户单次的内核调用称为一次**系统调用**;可以通过`syscalls`命令查看Linux下所有的系统调用

* GNU项目

  * Linux内核
  * GPL协议
  * GNOME桌面
  * GDB调试器
  * GCC编辑器
  * GNU图形工具

* Linux系统概述及安装

  * 多用户多任务的分时操作系统
  * 类UNIX的操作系统
  * Fedora
  * Ubuntu
  * RedHat
  * openSUSE
    * 德国著名Linux发行版，Novel公司维护 YasT软件包管理
  * Debian

## 系统架构

### 文件系统

文件是Linux中基础，具有所有者、所属组、权限、时间（mtime、ctime、atime）等属性；FS（File System，文件系统）是一个由文件组成的系统。Linux中
的FS是以树状结构的形式存在，起点为根目录`/`，每一个目录节点提供归属关系：CD（Child Directory，子目录）与PD（Parent Directory，父目录）；
且由根目录开始的所有途径的目录名和文件名组成该文件的绝对目录，从工作目录开始的所有途径的目录名与文件名组成该文件的相对目录。工作目录是Linux中的
一个变量，表示shell程序当前的工作目录，可以由`pwd`来获取或使用`cd`修改其值。在Linux中，目录是一种特殊的文件，其中`.`表示当前目录，`..`表示父
目录。当FS中新建一个文件时，会在工作目录建立一个指向该文件的HL（Hard Link，硬链接）；文件有HL才会被纳入FS，否则会被删除；而文件的硬链接数目
LC（Link Count，链接数）可以有多个，可以使用`ln`创建和`unlink`删除HL；为保持FS的树状结构，Linux系统推荐使用SL（Soft Link，软链接），新建
SL不会影响LC，其实质是`symbolic link`文件，包含有链接指向文件的绝对路径。编辑文件时，Linux只会将内容的编辑导向SL指向的文件，类似于Windows
的快捷方式，使用`ln -s`创建SL。可以使用`file`来查询文件的类型。

### 内核系统

Linux启动的过程有：内核的引导、运行init、系统初始化、建立终端、用户登录系统。


# 交叉编译busybox

下载busybox源码包：




aarch64-openwrt-linux-musl-


## 学习路线

### 基础学习

* 数据结构与算法：
    
    * 排序，KMP
    * 红黑树
    * B树以及B+树， 
    * hash
    * 图论


* 设计模式：

    * 创建型设计模式： 单例模式，工厂方法模式与与抽象工厂模式，原型模式
    * 结构型设计模式： 适配器模式，代理模式、桥接模式，组合模式
    * 行为型设计模式：策略模式，观察者模式，责任链模式，状态模式

* 工程管理：make,cmake,git

* Liinux基础学习

* 数据库：SQLlite, MySQL, Redis,MariaDB, 

### 网络设计

* 网络io与select以及poll与epoll
* reacter原理
* http服务实现
* websockert实现
* Apache，NGINX源码解析
* 网络协议栈
* 网络框架


### 基础组件

* 池化技术
* 进程通信
* 锁技术*
* 开源组件

### 中间件开发

* 事务操作
* REDIS
* MYSQL
* MondGB*

### 框架学习

* SykNet
* ZeroMQ*

### 内核分析

* 内存管理
* 进程管理
* 设备管理*




基础工具
=======

coreutiils


网络工具
=======

iproute2, net-tools
iw, wirreless-tools
netcat

networkmananager或者network

在使用iw或者wireless-tools时，networkmanager可能会产生影响，需要关闭NetworkManager服务。

bridge-utils用于管理虚拟网桥的工具。

uml_utilities





iproute2, net-tools

iw, wireless-tools



解压工具
======

zstd, gzip, bzip2, xz

虚拟环境
======

qemu



软件管理
=======

apt(apt-get, apt-cache), dpkg

yum, rpm

pacman, yay, paru


---------------
环境变量TERM标识终端类型：xterm、xterm-256color。xterm默认支持8色， xterm-256color默认支持256种颜色。可以通过`tput color`查看颜色。

