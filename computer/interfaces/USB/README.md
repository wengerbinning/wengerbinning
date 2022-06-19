# Universal Serial Bus

通用串行总线(USB, Universal Serial Bus)是由USB-IF开发的一种串总线口标准，也是一种输入输出接口的技术规范。
该标准是一个外部总线标准，用于规范计算机间或与外设的数据交互。

USB是在1994年底由英特尔联合多家公司于1996年推出的，速率为1.5Mbps；在1998年发布了USB1.1，速率达到了12Mbps。

在USB1.1的基础上开发的USB2.0，速率达到了480Mbps，可以向下兼容。

之后在USB3.0 Promoter Group制定了USB3.0标准，速率达到了5Gbps，

在实际应用中USB3.0称为“USB SuperSpeed”， USB2.0称为“USB HighSpeed”， USB1.1称为"USB FullSpeed".

USB3.1 Gen2标准的速率达到了10Gbps，（此前的USB3.0又称USB3.1 Gen1）

USB的版本有USB1.X、USB2.0、USB3.X、USB4。


**USB1.0**

USB1.0是由英特尔与微软发起的，于1995年正式发布的接口标准，支持热拔插、5V500mA的供电；速率是1.5Mibps。接口
是四个触点：5V、DATA+、DATA-、GND


-- USB2.0 采用4针的设计，接口常为黑色与白色， 速率为480Mbps。

-- USB3.0 采用9针的设计，接口常为蓝色，速率为5Gbps。


## 接口

4个针脚：USB1.x USB2.0
USB Type A
USB Type B

5个针脚： USB1.x USB2.0
USB mini Type A
USB mini Type B

USB micro Type A
USB micro Type B

9个针脚: USB3.0
USB3.0的接口


24个针脚：
USB Type C


## USB HUB

USB hub是一种扩展USB设备的设备，该设备直接或间接连接到USB root hub， root hub是整个USB hub模型中的顶层设备，
其他hub呈金字塔式连接到root hub，一般不超过5层。该设备可以整理下游设备的数据，并整合后传递到上游的设备，该设备类
似网络模型中的路由器（会对数据包进行重新封装），同时hub还是一个USB设备，可以向上级汇报下级设备的数量。


## USB设备的枚举过程

枚举就是主机从设备中读取一些信息，从而知道设备是什么设备、如何通信等，然后主机就可以根据这些信息来加载合适的驱动。

在USB架构中，hub负责检测设备的连接和断开，利用中断来告诉主机，


当主机收到中断信号，主机会发送一系列请求给设备所挂载的hub，由hub建立一条连接主机与设备的通信通道，然后主机以控制
传输的方式，通过端点0发送获取信息请求.处于顶层的hub是root hub,其他hub都是在root hub之下


USB协议定义了设备的6种状态，在枚举过程中，设备需要经历4个状态的迁移：上电状态(powered)、默认状态(default)、
地址状态(address)、配置状态(configured)。当USB设备接入hub端口时，hub给设备供电，设备处于上点状态；

 1     
**控制传输**

控制传输有setup 、确认数据，控制传输只能由主机发起。


**中断传输**

**同步传输**

**批量传输**

