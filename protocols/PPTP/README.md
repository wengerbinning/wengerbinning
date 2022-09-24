点对点隧道协议(PPTP, Point-to-Point Tunneling Protocol)是实现VPN的方案之一。

PPTP未实现数据加密与身份验证，是依赖PPP来实现安全特性的，可以利用PPP协议栈中的PAP、CHAP、
MS-HAP或者MPPE以及IPsec来实现。

PPTP有两个通道分别是管理通道与数据通道， 管理通道是基于TCP， 用于管理数据通道；数据通道是基于
GRE，用于传输PPP数据。




## 管理通道

PPTP管理通道是基于CS模式，服务端默认使用TCP的1723端口来接收客户端的请求。


**建立TCP连接**

**PPTP连接请求**

**



该协议最早由微软等厂商主导开发，1999年7月发布RFC 2637规格书。





