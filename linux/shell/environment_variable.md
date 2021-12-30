# 环境变量



环境变量是方便管理的机制，其中最常用的变量是PATH，是可执行程序的查询目录；还有工作目录存储在PWD变量中。

## 查找环境变量

```shell
export
env
printenv
```

## 设置环境变量

```shell
export <variable_name>=<variable_value>
declare
set
env
```

## 删除环境变量

```shell
unset <variable_name>
```

## 管理配置文件

通过以上的命令只是本次执行生效，如果想要永久生效，需要修对对应的配置文件。source用于立即生效配置文件

* 所有用户：`/etc/profile`.

* 对于当前用户：`~/bash_profile`、`~/.bash_login`、`~/.profile`，前两个针对SHELL为bash的配置文件，如果shell为zsh，则有`.zshrc`.


**特殊的环境变量**

* `PATH`是shell用来搜索可执行文件的路径，通常为各个二进制文件的存放路径，多个路径通过`:`来区分。
* `TERM`是




**pkg-config**

PKG_CONFIG_PATH
PKG_CONFIG_LIBDIR
