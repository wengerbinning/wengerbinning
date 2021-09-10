# pkg-config

pkg-config是以一个源码编译时查询已安装的第三方库的使用接口的计算机工具软件。原仅支持Linux，现已可以跨平台使用。其实质是查询*.pc文件

```file
# *.pc
prefix=/usr/local
exec_prefix=${prefix}
libdir=${exec_prefix}/lib
includedir=${exec_prefix}/include

Name:
Description:
Version:
Libs:
Cflags:
```