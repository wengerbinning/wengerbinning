主控控制器(Host Controller)是计算机端的USB控制器。主控控制器接口(HCI,Host Controller Interface)是一种描述外部设备的主控的寄存器的标准。
OHCI、UHCI、EHCI、xHCI是不同版本的标准，AHCI用于描述SATA设备，WHCI,VHCI。计算机中的USB控制器被称为主机控制器(Host Controller),USB设备
中的控制器（UDC），每条总线上只有一个主机控制器，负责协调主机和设备间的通信，设备端不能主动向主机发起通信。 


通用主控控制器接口(UHCI, Universal Host Controller Interface)支持USB1。

开放主控控制器接口(OHCI, Open Host Controller Interface)支持USB1.1。

增强主控控制器接口(EHCI，Enhanced Host Controller Interface)支持USB2

可扩展的控制器接口(xHCI,Extensible Host Controller Interface)支持USB1、USB2、USB3

(AHCI,Advnced Host Controller Interface)


主控控制器驱动(HCD,Host Controller Driver)


USB人机接口设备(HID,Human Interface Device)是鼠标、键盘等外围设备。



## 平台驱动

```c
// linux/platform_device.h
struct platform_driver {

}
```

## 设备驱动


```c
// linux/device.h
struct device_driver {

}
```