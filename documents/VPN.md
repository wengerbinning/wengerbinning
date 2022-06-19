# VPN

虚拟专用网络（VPN，Virtual Private Network）的功能是在公用网络上简历专用网络以实现远程访问。通过VPN网关可以实现对数据包的加密和数据包目标地址的转换。

其具体实现就是在LAN中设备搭建VPN服务，从而让远程设备通过VPN服务实现LAN的访问，整个访问过程中数据是被加密的，可以看做一个专用的数据链路上安全传输。

VPN网关是采用双网卡结构，远程设备A发送的数据会在VPN网关A处进行检测，如果目的地址数据LAN中设备B，则通过数据分装将数据发送给LAN中的VPN网关B，网关B对数据进行拆分，并将数据发送给设备B。

VPN的隧道协议：PPTP、L2TP、IPSec。

按照应用场景可以分为：

* 远程接入（Acess）VPN：设备到LAN访问。
* 内联网（Intranet）VPN：LAN与LAN访问。
* 外联网（Extranet）VPN：

按照设备可以分为路由器VPN与交换机VPN。

通过服务、软件、硬件实现VPN。