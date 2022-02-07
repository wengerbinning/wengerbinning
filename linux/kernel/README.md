. `crpto/`加密的API.
* `Documentation/`内核源码文档。
    
  * `CodindStyle`Linux内核编程风格。
  * `Kernel-doc-nano-HOWTO.txt`注释。
  * `oops-tracing.txt`
  
* `drivers`设备驱动层程序。
* `firmware`使用某些驱动程序而需要的设备固件。
* `fs`vfs与各类文件系统。
* `include`内核头文件。
* `init`内核引导和初始化。
* `ipc`进程间通信代码。
* `kernel`核心子系统。
* `lib`通用内核函数。
* `mm`
* `net`
* `samples`
* `scripts`
* `security`
* `sound`
* `usr`
* `tools`
* `virt`

* `COPYING`内核许可文件。
* `CREDITS`开发者列表。
* `MAINTAINERS`维护者列表。
* `REPORING-BUGS`
* `Makefile`

内核开发说明：

* 内核开发不能使用外部库文件。
* 内核开发推荐使用GNU C.
* 内核中每一个进程只有一个很小的定长栈。
* 
进程

物理内存

虚拟内存是

辅助内存


内存映射是虚拟内存到物理内存的映射


-------------------------

.*.o.cmd文件是内核编译生成*.o的依赖文件，其中有source_*、deps_*、cmd_*三类，其中source表示源码
deps表示依赖有文件