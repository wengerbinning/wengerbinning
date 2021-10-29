根据未剥离符号表的程序文件以及产生的core文件进行gdb调试。gdb命令会根据命令树来确定命令，例如backtrace，输入ba，bt就可以调用，即使用命令唯一字符子集就可以识别。

```shell
gdb <program file> <core file>
```

* 回溯所有的栈帧使用backtrace，即打印出所有的栈帧。如果打印不出来，使用show directories，然后追加directories变量的值

```gdb
backtrace
```

* 选择栈帧frame，后可以加栈帧索引，如果没有参数，则显示当前所在栈帧。

```gdb
frame <index>
```

* 打印程序相关信息info，该命令可以答应变量，寄存器等信息。

```gdb
info local 打印局部变量

```

* 打印表达式的值print，

```gdb
print <var>
```

* 打印变量类型

```gdb
ptype 
```

* 设置变量值

```gdb
set print pretty on
```

* 查看函数的反汇编代码disassemble。

```gdb
disassemble /m <function>
```


通用寄存器：

* CS: 
* SS:
* BS:
* EX:
* FS:
* GS:

* RSI
* RDI
* RBP
* RSP：保存栈顶地址的寄存器。
* RIP: 保存当前执行指令的地址的寄存器。




