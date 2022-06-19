dd用于指定大小的块拷贝，在拷贝的同时可以进行转换。

```shell
dd <command>...

command:
    if=<input file>            指定输入文件
    of=<output file>        指定输出文件
    ibs=<bytes>                指定一次读入的字节数
    obs=<bytes>                指定一次输出的字节数
    # bs=<bytes>            同时指定一次读入与输出的字节数
    skip=<blocks>            指定从输入中跳过的块
    seek=<blocks>            指定从输出中跳过的块
    cbs=<bytes>                指定一次转换字节数
    conts=<block>            指定转换的块数
    conv=<conversion>        指定转换的参数
```