make是一个根据Makefile自动构建的工具集，可以构建任何编程语言的项目。在使用make构建之前，需要你编辑一个makefile的文档，该文档是构建的依据。

makefile共有5部分组成：明确规则、模糊规则、定义变量、指令与注释组成。makefile的注释由`#`来标识。

## 变量

变量是由字母及下划线组成，在变量的赋值中有四种基本的赋值方式。简单赋值`:=`只对当前语句有效，递归赋值`=`对所有变量有效，条件赋值`?=`变量未定义是赋值，追加赋值`+=`在原来变量值后增加新值

* 变量定义

```makefile
OBJ = main.o type.o

$(OBJ)
${OBJ}
```

变量可以使用`$(<variable name>)`与`${<variable name>}`来使用变量。

* 环境变量是优先级最高的变量，会覆盖makefile中定义的变量并且在所有Makefile中共享变量。也可以使用make的参数来提供环境变量

```Makefile
CC=gcc
CFLAGS="-I/usr/include -I/include"

export CC CFLAGS
```

通过参数来提供环境变量。

```shell
make CC=gcc CFLAGS="-I/usr/include -I/include"
```

* 自动变量

  1. `MAKEFLAGS`变量会在调用子目录时执行
    
    ```Makefile
    # This is top makefile.
    MAKEFLAGS:=-rR
    all: 
    	cd sub module && $(MAKE)	
    ````
    
    在调用子模块时，会自动使用-w参数。

    ```Makefile
    # This is sub module.
    all:
    	@echo $(MAKEFILE)
    ```

* 模式变量


在Makefile中存在一些特殊的目标，同时存在两个相同目标，后面的会覆盖前面的目标来执行


* `all`

* `install`

* `dist`发布版本

* `.PHONY`是一个伪目标，也称为标签，指定依赖目标是一定会被执行，防止在项目中出现与目标同名的文件时该目标无效的问题。

* `FORCE`是一个伪目标，没有依赖与命令，所以当FORCE作为依赖是总会被执行。

* `clean`主要清除目标文件与可执行文件。

* `distclean`主要清除与发布版本有关的文件，包含Makefile与configure等。

* 空目标是伪目标的变种用来记录上一次执行此规则定义命令的时间。和伪目标不同的是：
这个目标可以是一个存在的文件，一般文件的具体内容我们并不关心，通常此文件是一个空文件。
空目标文件命令部分都会使用“touch”在完成所有命令之后来更新目标文件的时间戳，记录此规则
命令的最后执行时间。 make 时通过命令行将此目标作为终极目标，当前目录下如果不存在这个文
件，“touch”会在第一次执行时创建一个空的文件（命名为空目标文件名）。空命令的唯一作用是防止make在执行时，试图为重建这个目标去查找隐含命令


## LINKS

[GNU make](https://www.gnu.org/software/make/manual) 是GNU项目中一个子项目.

