ip




```shell
ip a
```

```shell
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
    inet6 ::1/128 scope host 
       valid_lft forever preferred_lft forever
#
2: enp3s0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc fq_codel state UP group default qlen 1000
    link/ether 1c:69:7a:2e:f7:77 brd ff:ff:ff:ff:ff:ff
    inet 192.168.122.251/24 brd 192.168.122.255 scope global noprefixroute enp3s0
       valid_lft forever preferred_lft forever
    inet6 2408:8640:8ff:f:122::8f2/128 scope global dynamic noprefixroute 
       valid_lft 3712sec preferred_lft 1462sec
    inet6 fe80::4dcd:fa72:8062:f859/64 scope link noprefixroute 
       valid_lft forever preferred_lft forever

# mtu 1500
# 最大传输单元(MTU, Maximum Transmission Unit)

# qdisc fd_codel
# 排队规则(QDISC, queueing discipline)

# state UP
# 状态(state)

# group
# 

# qlen
#

# link/ether <mac address> brd <>

# inet <ipv4>/<subnet mask> brd <> scope global noprefixroute enp3s0

# inet6 <ipv6>/<network portion> scope global dynamic noprefixroute

```
