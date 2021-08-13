# SHELL

Shell是Linux的终端控制程序，是处理计算机与人之间交互的程序；在众多的shell中，bash是大多
Linux发行版本默认shell。zsh是我喜欢的shell。

## 文档注释

在shell编程中,通常以`#`标识注释,增强程序的可读性。在shell脚本中,通常在第一行使用`#!`来指定
执行脚本的shell程序。在接下来的学习中,一般以bash为默认shell，例如`#!/bin/bash`。

* 多行注释：

  ```bash
  <<COMMENT
  可以作为多行注释，其中COMMENT可以是任意字符。
  COMMENT
  ```

## 数据对象
-------------------------------------------------------------------------------

shell中数据对象只能存储字符类型的数据，且赋值符号左右不留空格。

* 数据对象示例：

  ```shell
  # 变量的定义格式。
  <varible name>=<string value>
  # 在定义格式的基础上可以使用以下两种格式，将命令执行后的返回结果赋值给变量。
  # 第一种格式
  <variable name>=`<command>`
  # 第二种格式
  <varible name1>=$(<command>)
  # 当然也是可以使用变量间相互赋值的。
  <variable name 1> = ${<variable name  2>}
  # shell中也支持数组。
  # 第一种格式
  <array_name>=(<value_0>,<value_1>)
  # 第二种格式
  <array_name>=(
      value_0
      value_1
  )
  # 第三种格式，可以不使用连续下标,且下标无限制。
  <array_name>[0]=<value_0>
  <array_name>[999]=<value_999>
  ```

* 数据的对象的使用，使用`$`来标识变量对象。

  ```shell
  # 输出数据对象，这两种格式
  echo $<varible_name>
  echo varible=$<variable_name>
  #这种格式的输出与上面个相似，可以转义变量名与转义字符。
  echo "Variable = $<variablename>"
  # 这种合适的输出不能转义变量名与转义字符，会将所有的字符当做普通字符输出。
  echo 'Variable = $<variablename>'
  # 使用以下格式来对字符串变量来进行切片。
  echo ${<variable_name>[:<start_index>:<count>]}
  # <https://www.cnblogs.com/quzq/p/12104360.html>
  echo ${#variablename}                                       # 获取字符串的长度
  echo ${<groupname>[<index>]}                                # 显示数组元素
  echo ${<groupname>[@]}                                      # 显示所有元素
  echo ${#<groupname>[@]}                                     # 获取数组长度
  echo ${#<groupname>[*]}                                     # 获取数组长度
  echo ${<variable_name>#*demo}                                   # 符号#表示从左到右匹配到/之前的字符串。
  echo ${<variable_name>##*demo}                                  # 符号#表示从右到左匹配到/之前的字符串。
  echo ${<variable_name>%demo*}
  echo ${<variable_name>%%demo*}
  ```

* 变量的属性

  ```bash
  # 限定变量为只读变量
  readonly <variable_name>=
  # shell脚本中的变量默认是全局变量，函数中定义的也是，但是在函数中可以显式定义为局部变量
  local <veriable_name>=
  ```

* 删除变量

  ```bash
  unset <variable_name>
  ```

* 变量类型：在shell中存在三种变量:局部变量(当前shell实例中有效),环境变量(所有程序都能访问),shell变量(shell程序设定的特殊变量).

## 数据管理

### 数据输入

* 数据的输入: 在bash中只能输入字符

```bash
read <variablename>     # 读入文本并赋值给变量
```

### 数据输出

* 数据的输出: 输出文本到屏幕

```bash
# echo 输出字符
echo string         # 输出字符串
# 不换行显示,默认换行显示,-e开启转义
echo -e "string \c"

# printf 输出字符
printf "%10s %20s\n" "Name:" $name # 格式化输出,第一个参数为格式化字符串 之后依次为格式化参数
```

`printf`的转义字符与格式化字符: 转义字符只在格式化字符串中被解释,在格式化字符串,在%之后首先是属性{-(左对齐,默认右对齐),+(显示符号),#,0(以零填补)},然后是精度值,之后是格式化字符,例如`%-50s`表示固定50个字符长度,左对齐.

| 字符 | 说明 | 字符 | 说明 |
|:----:|:--- |:----:|:--- |
| \a | 警告字符 | %c | ASCII字符,显示参数的的第一个字符 |
| \b | 后退 | %d or %i | 十进制数 |
| \c | *禁止换行符 | %e or %E | 浮点数 |
| \f | 换页 | %f | 小数形式 |
| \n | 换行 | %g or %G | 自动选择小数形式 |
| \r | 回车 | %s | 字符串 |
| \t | 水平制表符 | %u | 无符号十进制数 |
| \v | 垂直制表符 | %x or %X | 无符号十六进制 |
| \\ | \符号 | %% | %符号 |

## 数学运算

在bash中,数字于运算符都会被当作普通文本,不能便捷的进行数学运算;但可以通过$(())语法来进行数值运算,运算符有{`+`,`-`,`*`,`/`,`%`,`**`,`=`，&，|，~};其优先级从高到低是乘方,乘除取余,加减;同一优先级按从左至右的顺序执行.

```bash
reasult=1+2                # 不会计算值,原样赋值
echo $reasult              # 原样打印
echo $((1+2*3/$reasult))   # 计算后打印结果
reasult=$((1+2**3))        # 运算后赋值
"$(echo ls)"               # 首先执行括号内的语句，执行的输出结果再次执行。

# 算数运算符 + - * / % ** = != == 用于数值运算
# 关系运算符 -eq -ne -gt -lt -ge -le 用于数值关系
# 逻辑运算符 !(非) -a or &&(与) -o or ||(或)
# 字符串运算符 = != -z -n $
# 文件检测运算符 -b -c -d -f -g -k -p -u -r -w -x -s -e -S -L
# 使用expr(表达式计算工具)
```

> Note: bash中提供一个let工具用于数值运算。

### 返回代码

在linux中,每个可执行程序会有一个整数的返回代码,在bash可以通过`$?`获取返回代码.在linux中可以使用`;`来在一行区别多条语句.

```bash
gcc foo.c      # 编译 fooc.c文件
./a.out        # 执行a.out程序
echo $?        # 打印a.out的返回代码
cd /; ls       # 多语句执行
rm demo.file && echo "rm succeed"  #在第一条语句返回代码为0(执行成功时),执行第二条语句
rm demo.file || echo "rm fail" #在第一条语句返回代码非0(执行失败时),执行第二条语句
```

### shell脚本

多行的bash命令写入一个文件即为bash脚本文件,执行时逐行执行,一般使用`.sh`或`.bash`来标识脚本文件,其目的达到代码复用.

* 脚本举例: 第一行说明该脚本使用的shell

```bash
#!/bin/bash         # 指定脚本执行shell
echo Hello
echo World
```

* 脚本参数: 脚本运行时,可以携带参数,使用`$<number>`获取参数值;

```bash
#!/bin/bash

echo $0         # 命令
echo $1         # 第一个参数

# $# 参数个数
# $* 所有参数
# $$ 脚本当前PID
# $! 后台运行的最后一个进程的PID
# $@ 所有参数
# $- 显示shell使用的当前选项
# $? 程序的返回代码
```

* 脚本的返回代码: 正常退出时自动返回0,也可以使用`exit <number>`指定返回代码;脚本在遇到`exit`指令会立即退出;

```bash
#!/bin/bash

lscpu >> $1

exit 0
```

## 功能函数

函数将具体功能进行封装，在shell函数中，可以有参数，且参数是局部变量，返回值只能是数值，用于表示函数执行结果，如果想要返回计算结果只能通过全局变量来传递。

* 函数的定义：通过function来标识，当然function也可以去掉。

```shell
# 带function标识的函数定义
function func() {
    lscpu
}

# 省略function标识的函数定义
func() {

}
```

* 函数的参数: 函数的参数是局部变量，只能在在函数内部使用，且使用方式与脚本参数使用方式相同。

```shell
function func() {
    lscpu >> $1
}

func demo.log # 指定参数
```

* 脚本件的函数调用: 使用`source`命令实现函数在脚本间的调用;

```bash
# demo1.bash
#!/bin/bash

function func()
{
    lscpu >> $1
}

# demo2.bash
#!/bin/bash

source demo1.bash   # 加载脚本
func demo.log       # 脚本间的参数调用

```

## 程序结构

### 分支结构

#### 条件判断

* 数值比较：

  ```shell
  # 相等判断使用eq，即equal。
  test 3 -eq 3
  # 不相等判断使用ne，即unequal。
  test 3 -ne 3
  # 大于判断使用gt，即greather than。
  test 3 -gt 3
  # 大于或等于判断使用ge， 即greather than or equal。
  test 3 -ge 3
  # 小于判断使用lt， 即less than。
  test 3 -lt 3
  # 小于等于判断le， 即less than or equal。
  test 3 -le 3
  ```

* 字符比较：

  ```shell
  # 相等比较。
  $str_1 == $str_2
  # 不相等比较。
  $str_1 != $str_2
  # 大于比较。
  $str_1 > $str_2
  # 大于等于比较
  # 小于比较
  $str_1 < $str_2
  # 小于等于比较
  # 字符串是空串判断
  -z $str
  # 字符串非空判断
  -n $str

  str_1="wengerbinning@163.com"
  str_2="wengerbinning@gmail.com"
  if [ $str_1 = $str_2 ]; then
      echo str_1 & str_2 is same.
  else
      echo str_1 & str_2 is different.
  fi
  if [[ $str_1 == *@*.* ]]; then
    echo str_1 is a email.
  fi  
  ```

  > Note: 在使用`[]`包含两个字符串比较时，需要确认两个字符串均为非空字符串，可以增加前后缀或者使用[[]]。同时`[[]]`也支持正则比较。但是`[[]]`

* 文件检测：

  ```shell
   # 文件是否存在, 输出0表示文件存在。输出1表示文件不存在。
   test -e demo; echo $?
   # 普通文件是否存在
   test -f demo; echo $?
   # 目录文件是否存在 
   test -d demo; echo $?
   # 脚本编程软连接文件是否存在
   test -L demo; echo $?
   # 文件是否可读
   test -r demo; echo $?
   # 文件是否可写
   test -r demo; echo $?
   # 文件是否可执行
   test -x demo; echo $?
   # 文件存在且不为空
   test -s demo; echo $?
   # 字符特殊文件是否存在
   test -c demo; echo $?
   # 块特殊文件是否存在
   test -b demo; echo $?
  ```

* 逻辑判断: 使用`test`命令来进行逻辑判断,{`-gt`,`-lt`,`-eq`,`-ne`,`-ge`,`-le`}分别表示大于,小于,等于,不等于,不小于,不大于,用于数值测试;

```bash
# 数值判断
    test 3 -gt 2; echo $?   # 3大于2成立时,返回代码为0;显示返回代码
    test 3 -lt 2; echo $?   # 3小于2不成立,返回代码为1;显示返回代码

# 字符串判断
    # 文本相同
    test abc=abx; echo $?
    # 文本不同
    test abc!=abx; echo $?
    test apple>tea; each $?     # 根据词典顺序,文本在另一文本之前
    test apple<tea; echo $?     # 根据词典顺序,文本在另一文本之后
    test -z <string>; echo $?   # 字符串长度为零时为真
    test -n <string>; echo $?   # 字符串长度不为零为真

# 逻辑组合
    !<expression>                  # 非
    <expression1> -a <expression2> # 与
    <expression1> -o <expression2> # 或

# if 条件语句,经常与test语句连用
    if [ <expression> ]
    then        # if的隶属代码,条件为真时执行
        echo content
    fi
    if [ 1 ]; then echo true; fi
# if-else 条件语句,可以使用if嵌套实现多分枝结构
    if [ -e $filename ]
    then
        echo <content>
    elif [ <expression> ]
    then
        echo <content>
    else
        echo <content>
    fi
  # efwfwfwfwf
   if [ -n "$1" ]; then
       echo dede
   elif [-z "$1" ]; then
       echo efwef
   else
       echo efwfwe
   fi
# case语句实现多程序执行,可以使用文本通配符,*表示任意文本,a?b表示a与b任意一个字符,[a-z]表示a-z之间的一个字符
    case $var in
    root)
        lscpu
        echo "you are $var"
    ;;
    vamei)
        echo "you are $var"
    ;;
    -f|--file)
      echo file
    ;;
    *)
        echo "you are the others"
    ;;
    esac
```

* 循环结构: 重复执行某段代码;

```bash
#!/bin/bash

now=`date+'%Y%m%d%H%M'`
deadline=`date --date='1 hour'+'%Y%m%d%H%M'`
# while 循环语句
while [$now -lt $deadline]
do  # while 隶属代码
    date
    echo "not yet"
    sleep 10
    now=`date+'%Y%m%d%H%M'
done
#for 循环语句: 执行'ls log*'语句,并以空格分割,之后依次赋值给var,并执行for隶属代码
for var in `ls log*`
do  #for 隶属代码
    rm $var
done
# 构建空格分割文本
MT7615((i=1;i<=5;i++))
do
    each $i
done
# seq生成等差数列
seq 1 2 10   # 第一个参数为起始,第二个参数为步长,第三个参数为终止
let 'index++'   # 标识index自增一个单位

for var1 in `seq 1 2 10`
do
 echo $var1
done
# break 可以跳出当前循环结构,continue跳出本次循环

# 无线循环
while :   # 等价于 while true
do
    <content>
done

for (( ; ; ))

# until 循环语句

until [ <condition> ]
do
    <content>
done
```

### 输出/输入重定向

一般情况,标准输出/输入都是以终端为对象,重定向是以其他作为对象;一般在Linux中 执行命令时会打开标准输入文件(stdin,文件描述符为0)、标准输出文件(stdout,文件描述符为1)、标准错误文件(stderr,文件描述符为2).

```bash
# 重定向输出至文件,将stdout重定向到file中
<command> > <filename>      # 直接覆盖文件
<command> >> <filename>     # 追加在文件末尾
<command> > <filename> 2>&1       # 将stderr与stdout合并输出到file
# 重MT7615定向输入至文件,将stdin重定向到file中
<command> < <filename>
<command> < <filename> 2<&1        # 将stderr与stdout合并输入
"dwdwd << <tag> <content> <tag>"                      # 将tag之间的内容作为输入
# 将文件描述符为n重定向到file,将stderr重定向到file
<command> <number> > <filename>     # 覆盖的方式
<command> <number> >> <filename>    # 追加的方式
```

如果执行命令后不想输出结果,则可以将输出重定向到`/dev/null`中,`/dev/null`中的内容都会被丢弃.

### 文件的包含

文件的包含用于在一个文件中使用另一个文件代码内容,通常以`. <shellfilename>`(顿号与文件之间的空格不可省略)或`source <shellfile>`来包含.

```bash

. ./bashfile

source bashfile
```

## 工具集合

### date

date是shell进行时间运算的工具

```shell
# 使用YYYY/mm/dd HH:MM:SS的格式操作。
date +"%Y/%m/%d %H:%M:%S"
```
### nc

nc是用来设置路由信息的工具。

* TCP端口扫描：

  ```shell
  # nc -v -z -w2 <ip> <port>
  nc -v -z -w2 192.168.0.3 1-100
  ```

* UDP端口扫描：
  
  ```shell
  # nc -u -z -w2 <ip> <port>
  nc -u -z -w2 192.168.0.3 1-100
  ```

* 扫描指定端口：

  ```shell
  nc -nvv 192.168.0.1 80
  ```

### tr

（tr，translate）工具主要用于压缩重复字符、删除文件中的控制字符以及进行字符转换操作。

```shell
# 替换重复字符串
tr -s str_1 str_2
# 删除字符
tr -d str_1
# 字符替换
tr -t str_1 str_2
# 字符集替补
```

### awk

awk是一个处理文本的工具。是由Alfred Aho， Peter Weinberger & Brian Kernighan开发。

```shell
# @#:
# @#:
# @#:
# @#:

# usage A: awk [<POSIX or GNU style options>...] -f <progfile> [--] <file>...
# usage B: awk [<POSIX or GNU style options>...] [--] <program> <file>...

# option
#     -f
#     -F
#     -v
#     -b
#     -c
#     -C
#     -d
#     -D
#     -e
#

# 通过自定义命令对输入文件进行处理。
awk {cat} <file>
# 通过指定脚本来执行。
awk -f <script> <file>
# 通过指定字符对输入文件进行分割
awk -F ',' <command> <file>

```

### cut
-------------------------------------------------------------------------------

```shell
# @#: cut
# @#:
# @#:
# @#:
# usage: cut <option>... [<file>...] 

# option:
#     -b, --bytes=<byte list>:
#     -c, --characters=<charscter list>:
#     -d, --delimiter=<delimiter>:
#     -f, --fields=<field list>:
#     -n: ignored
#     -s, --only-delimited:
#     -z, --zero-terminated:
#     --complement:
#     --output-delimiter=<string>:
#     --help
#    --version
```

### sed

sed是采用流编辑模式的文本编辑器，sed会根据流规则来编辑文本。sed默认不会修改源数据而是将数据复
制到缓存区。每次仅处理一行数据，处理完后再处理下一行。

* 使用格式说明：

  ```shell
  # @#: sed执行的结果将默认保存在缓存区，并不会直接修改源文件。如果没有指定-e与-f参数，则默
  # @#: 认将第一个非选项参数作为sed脚本，其他非选项参数作为输入文件，如果为输入文件，则读取
  # @#: 标准输入。如果有多个sed command script，每一个sed command可以使用-e参数，或者使
  # @#: 用semicolon。当然对于a,c,i这几个sed command由于其特殊性，后面不能跟semicolon，
  # @#: 所以只能使用-e参数，获将该command放在最后。
  # usage: sed [<option>...] <sed command script> [<input file>...]
 
  # option:
  #    -n, --quiet, --silent:　抑制匹配模式的自动打印，即只输出匹配到的结果。
  #    -e <script>, --expression=<script>: 将脚本添加到执行的命令中。
  #    -f <script file>, --file=<script file>: 将脚本文件添加到执行的命令中。
  #    -i[<suffix>]， --in-place[=suffix]: 将直接修改源文件，如果提供后缀将进行备份,提
  #        示:后缀与-i参数直接相连，中间没有空格。
  #    -l <N>, --line-length=<N>: 为 'l' 命令指定所需的换行长度,默认70个字符换行。
  #    -E, -r, --regexp-extend: 在脚本中使用正则表达式扩展。
  #    -s, --separate: 将文件视为单独的而不是单个、连续的长流。 
  #    -u, --unbuffered: 从输入文件加载最少量的数据并更频繁地刷新输出缓冲区。
  #    -z, --null-data: 用 NUL 字符分隔行。
  #    -b, --binary: 使用二进制模式打开文件。
  #    --debug: 注释程序执行，即对输出结果进行说明。
  #    --follow-symlinks: 就地处理时遵循符号链接。
  #    --posix: 禁用所有的GNU扩展。
  #    --sandbox: 在沙箱模式下运行（禁用 e/r/w 命令）。
  #    --help: 显示帮助信息。
  #    --version: 显示版本信息。

  # sed command script: [<line address>]<sed command>
  #     line address: 是一个可选的行地址，可以是单行地址，多行地址以及正则表达式。
  #         a single line number:
  #         a range of lines:
  #         a regular expression:
  #     sed command:
  #         a\<text>， a <text>: 在行后添加text。
  #         b: (@!)无条件分支到标签。 标签可以省略，在这种情况下开始下一个循环。
  #         c\<text>, c <text>:  使用text替换行。
  #         d: 删除匹配内容，直接进入下一个循环。
  #         D: (@!)如果模式空间包含换行符，则删除模式空间中直到第一个换行符的文本，并使用结
  #            果模式空间重新开始循环，而不读取新的输入行。
  #         e [<command>]: 没有command时，执行在模式空间中找到的命令并用输出替换模式空
  #             间； 尾随换行符被抑制。有command时，执行命令并将其输出发送到输出流。 该命
  #             令可以跨多行运行，除最后一行以外的所有行都以反斜杠结尾。 
  #         F: 打印当前输入文件的文件名（带有尾随换行符）。
  #         g: 用保持空间的内容替换模式空间的内容。
  #         G: 将换行符附加到模式空间的内容，然后将保持空间的内容附加到模式空间的内容。
  #         h: (hold) 用模式空间的内容替换保持空间的内容。
  #         H: 将换行符附加到保持空间的内容，然后将模式空间的内容附加到保持空间的内容。
  #         i\<text>, i <text>: 在一行前插入文本。
  #         l: 以明确的形式打印模式空间。
  #         n: 如果没有禁用自动打印，则打印模式空间，然后无论如何用下一行输入替换模式空
  #             间。 如果没有更多输入，则 sed 退出而不处理任何更多命令。
  #         N:向模式空间添加一个换行符，然后将输入的下一行附加到模式空间。 如果没有更多输
  #             入，则 sed 退出而不处理任何更多命令。
  #         p: 打印模式空间。
  #         P: 打印模式空间，直到第一个 <newline>.
  #         q[<exit code>]: 退出 sed 而不处理任何命令或输入。 
  #         Q[<exit code>]: 此命令与q相同，但不会打印模式空间的内容。与q一样，它提供了向
  #             调用者返回退出代码的能力。
  #         r <filename>: 读取文件名。
  #         R <filename>: 在当前循环结束时或读取下一个输入行时，将一行要读取的文件名排队
  #             并插入到输出流中。
  #         s/<regular expression>/<replace string>/[<flags>]:（替代）将正则表达式
  #             与模式空间的内容进行匹配。 如果找到，用替换替换匹配的字符串。
  #             flags:
  #                 p: 打印替换后的结果。
  
  #                 <number>: 替换第几次匹配到的字符。有效范围1~512
  #                 g:替换全局所有的匹配字符。
  #                 w <filename>: 将替换后的结果写入文件。
  #         t <label>, T <label>: （测试）仅当自读取最后一个输入行或采用条件分支以来没有
  #             成功替换时才分支到标签。 标签可以省略，在这种情况下开始下一个循环。
  #         v [<version>]: (version) 此命令不执行任何操作，但如果不支持 GNU sed 扩展
  #             或请求的版本不可用，则会使 sed 失败。
  #         w <filename>: 将模式空间写入文件名。
  #         W <filename>: 将模式空间的一部分写入给定的文件名，直到第一个换行符
  #         x: 交换保留空间和模式空间的内容。
  #         y/<src string>/<dst string>: 将模式空间中与任何源字符匹配的任何字符与目标
  #             字符中的相应字符进行音译。
  #         z: (zap) 该命令清空模式空间的内容。
  #         #: 一条评论，直到下一个换行符。
  #         {<cmd>;...}:将多个命令组合在一起。
  #         =: 打印当前输入行号（带有尾随换行符）。
  #         :label: 指定分支命令的标签位置 (b, t, T)。

  # regular :
  #      \s: 表示

  # exit status： 除了以下标准的返回代码，还可以使用q或者Q指定返回代码。
  #     -0： 成功执行。
  #     -1： 语法错误。
  #     -2： 文件不能打开。
  #     -4： IO错误。
  ```

### grep

grep可以用于字符串匹配


* 正则匹配字符：




bc： 一个计算机工具

obase = 2 # 设置输出为2进制
ibase = 10 # 设置输入为10进制
