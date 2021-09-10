# gcc

## 基本参数

```shell
# 指定编译语言：c,objective-c,c-header,c++,cpp-output,assembler,assembler-with-cpp.或者为none，则取消之前设定的语言指定，开启默认的智能识别（根据文件后缀名。
-x <programming language>
# 预处理源文件。
-E
# 预处理时不删除注释信息。
-C
# 编译成汇编文件，即*.s.
-S
# 汇编成二进制文件，即*.obj。
-c <file name>
# 生成可执行文件
-o <file name>
# 包含一些文件。
-include <file name>
# 指定头文件搜索目录
-I <directory>
# -I-
# -idurafter dir
# -iprefix prefix
# -iwithprefix dir
# 生成文件关联的信息。
-M
#－ＭＭ
# -MD
# -MMD
# 指定搜索库的路径
-L <directory>
# 用于指定库路径下的库。
-l
# 编译器优化
-O {0,1,2,3}
# 在编译时产生调试信息。
-g
```

## 生成库文件

静态库是*.a;动态库是*.so,都是由*.o文件生成的。

* 生成动态库：

  ```shell
  gcc -fPIC -shared hotplug.c -o libusb.so `pkg-config --libs --cflags libusb-1.0`
  ```
* 使用ar生成静态库：

  ```shell
  ar -rt libtest.a test.o demo.o
  ar cr libtest.a demo.o test.o
  # -r 在库中插入模块，存在时替换。
  # -c 创建一个库，
  # -s 创建文件索引，ranlib可以为无索引的库添加索引。
  # 显示库中的模块。
  ar tv libdemo.a
  # 显示库的索引表。
  mn -s lib.a

  # 使用静态库：
  gcc -o main -L/lib -ltest -g main.c
  ```

* 使用gcc生成动态库：在使用动态库是需要将库的路径加入`LD_LIBRARY_PATH`变量中.

  ```shell
  # 使用fPIC标签生成*.o文件。
  gcc -fPIC -c demo.c
  # 传递 -shared标签给gcc
  gcc -shared libtest.so demo.o
  ```