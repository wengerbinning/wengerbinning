* 预处理是处理元文件中的预处理指令，使用`gcc -E`或`cpp`预处理器可以生成预处理后的文件，也称为编译。

```shell
gcc -o hellworld.i -E hellworld.c
```

```shell
cpp helloworld.c > helloworld.i
```

* 编译是将预处理之后的文件编译生成汇编文件，使用`gcc -S`或`cc1`编译器可以实现编译过程。

编译过程经过了词法分析、语法分析、语义分析以及优化等几个过程。将其他编程语言编写的代码转化为汇编代码。

```shell
gcc -o helloworld.s -S helloworld.i
```

* 汇编是将汇编代码转化为二进制序列的过程，通过`gcc -c`或`as`汇编器来实现汇编过程。

```shell
gcc -o helloworld.o -c helloworld.s
```

* 链接是将各模块的二进制序列组装成一个可执行程序的路过程，通过`gcc`或`ld`链接器实现链接过程。

```shell
gcc -o helloworld helloworld.o
```