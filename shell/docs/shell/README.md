
* `echo`是shell内置的命令，用于显示内容。

echo具有以下参数

  `-e`打开转移序列的开关	







---------
使用exec可以用来打开一个文件并指定一个文件描述符

```shell
# 使用文件描述符3指定到log.txt文件。
exec 3>>log.txt

echo comment >&3


``` 
