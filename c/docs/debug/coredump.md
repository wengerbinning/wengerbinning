core文件是程序在异常时生成的，该文件包含程序运行时的内存，寄存器状态，堆栈指针，内存管理信息还有各种函数调用堆栈信息等。该文件满足ELF格式，readelf可以确认一个文件为core文件。

配置core文件的的命名规则以及路径：`/proc/sys/kernel/core_pattern`，%e表示程序名称。

```shell
echo '/data/coredump/core.%e.%p' >/proc/sys/kernel/core_pattern
```

配置core文件命名是否带进程id：`/proc/sys/kernel/core_uses_pid`

```shell
echo 1 > '/proc/sys/kernel/core_uses_pid'
```

系统产生coredump的条件是确认当前会话的ulimit -c，若为0则不会生成core文件，
