在调试文件之前需要确保程序文件包含符号表，即在编译时使用了`-g`参数，并且程序不能被strip程序移除符号表。
通过file可以确认是否被移除符号表。之后开始调试程序。

```shell
# 调试本地程序。

$ gdb <program path>
# exampile: gdb ./helloworld
```

通过以上行为，正确结果应该是进入gdb调试交互页面。在进入调试程序之后，可以参照以下程序来进行调试。

```gdb
# 设置main函数断点。

(gdb) break main

# 开始运行程序，直到遇到断点停止运行。

(gdb) run
```