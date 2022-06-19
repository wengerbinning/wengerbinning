
GNU Build System


autoconf
=========

autoconf一个用来生成项目自动配置脚本(configure)的工具，这个脚本可以自动化配置项目源码以适应在不同的POSIX系统上构建目标代码，该脚本在执行时无需依赖autoconf，所以在执行期间无需autoconf的支持。

configure执行后可以生成多个Makefile、头文件、shell脚本(config.status, config.cache)、configure.log一些自己的测试内容，你还需要提供aclocal.m4与acsite.m4；如果你要使用头文件

autoconf在生成这些文件之前，需要我们建立一个autoconf的输入文件configure.ac,如果你


automake
=========

automake需要你使用一种简单的语法实现Makefile.am然后使用该工具生成一个Makefile.in供autoconf使用。


config.guess config.sub itmain.sh itconfig
==========================================

这些文件是根据libtoolize生成的。


aclocal.m4
==========

这份文件是由aclocal生成的文件。

configure.h.in
==============


configure
=========

这份文件是由autoconf读取configure.in生成的文件。

---------

Makefile.am
===========

是一些编译的选项及要进行编译的文件。

Makefile.ac
===========

这份文件是由autoscan根据Makefile.am生成的文件。

Makefile.in
===========

这份文件是由automake读取Makefile.am生成的文件。

Makefile
========

这份文件是执行configure读取Makefile.in之后生成的文件。