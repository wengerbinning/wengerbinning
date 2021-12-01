# 命令行工具

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
