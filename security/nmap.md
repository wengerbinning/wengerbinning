nmap在扫描前会判断主机是否存活。


-sS TCP的SYN扫描


Host Discovery

```shell

-sL    # 只显示需要扫描的主机。

-sn    # 在主机发现之后不做端口扫描。

-Pn    # 跳过主机发现

-PS[<port list>]   # 设置SYN标志,默认目的端口为80， 

-PA[<port list>]   # 设置ACK标志

-PU                # 使用UDP ping
```

Port Scanning

```shell

-sS

-sT

-sU

-sY


```
