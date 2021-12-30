shell是一个命令解释器，建立了用户和操作系统之间的接口，当用户输入一条命令后，shell对命令进行解析，
然后调用相应的程序来执行。这些命令根据是否是shell程序内部支持可以分为内部命令与外部命令，而且shell
解释程序有bash,tcsh等。

命令行工具是可以在终端执行的软件，这些工具可以分为shell内置的命令与第三方的命令。

## SHELL内置的命令

* `echo`
* `type`是一个识别命令类型的命令通过`type <command>`可以识别命令是内置还是第三方。
* `wait`是一个等待工作完成并返回结构的命令。


## 第三方命令

与系统管理有关的命令有

* `hostname`
* `date`
* `uname`
* `script`

关于文件管理的基础命令有

* `touch`
* `mkdir`
* `ls`
* `cp`
* `mv`
* `rm`
* `tr`
* `od`
* `cat`
* `cut`
* `sed`
* `less`
* `more`
* `head`
* `tail`
* `sort`
* `grep`
* `uniq`
* `diff`
* `file`

与文件归档与压缩有关的命令

* `tar`

* bzip2
* bunzip2
* bzcat
* bzip2recover
* gzip
* gunzip
* zcat
* compress

与打印机有关的命令有

* `lpr`
* `lpq`
* `lprm`


与基础办公有关的工具

* `bc`

与跨平台有关系的命令

* `unix2dos`
* `dos2unix`

与账户管理有关的命令

* `w`
who
finger

write
mesg

与命令定位与查询有关的命令

which
whereis
* `apropos`可以使用关键字来搜索工具，需要使用数据库whatis,有makewhatis工具来维护。
* `slocate`slocate是locate的安全版本。

----------------------------------
shell处理命令，tty驱动设备检查每一个字符，当按下回车，驱动将字符缓存区的字符传递给shell来处理。

----------------------------------
在shell的命令中，语法格式大致类似，具体格式的细节需要根据具体命令来使用。一般命令的由命令与参数构成。
在参数中有一类特殊的参数称为选项，一般是带有前缀的-或者--，来指定命令的执行方式。各个参数之间使用空格
分割，在选项中可以将多个合并到一起。一般通过--来表示选项的结束，参数的开始。


----------------------------
重定向(redirection)是改变shell原有的标准输入等。使用

```shell
# 
ls > text


````

## 语句








## 脚本










------------------------------


shell是用户与操作系统进行交互的接口。是一个命令解释器。shell存在多种，例如bash、tcsh、zsh。
在shell中，在按下回车后会对当前输入进行解释执行。


在shell中有一下几个快捷键

Ctrl + H, 删除字符。
Ctrl + W, 删除一个单词。

Ctrl + U，删除一行
Ctrl + X，





Ctrl + Z, 挂起任务。
Ctrl + C, 终止任务。

除此之外，也可以通过stty来设定自己的快捷键。


-----

Linux存在详细的联机文档。


以下一些Linux的工具：
* less
* man

* info
