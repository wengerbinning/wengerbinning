minicom是由Miquel van Smoorenburg负责开发的基于类UNIX的终端模拟器，
```shell
usage: minicom [<option>] [<configure file>]

option:
    
    -b, --baudrate           : set baudrate
    -D, --device             : set device name
    -c, --color=on/off       : ANSI style color usage on or off.
    -C, --capturefile=<file> : start capturing ti file.
    
configure file
    
    this is a configure file in /etc/minicom/ and prefix is minirc, default configure file is minirc.dfl.
    
```

* 配置文件：`/etc/minicom/`
    
    * 默认配置文件：`/etc/minicom/minirc.dfl`
    * 其他配置文件：`/etc/minicom/minirc.*`