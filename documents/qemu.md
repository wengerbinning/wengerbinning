qemu（Quick EMUIator）是一套Fabrice Bellard开发程度以GPL开源的处理器模拟系统，在GNU/Linux平台上广泛使用，Bochs、PearPC等与其类似，通过kqemu加速器可以使qemu接近物理主机的速度；在0.9.1版本之前使用kqemu加速器，之后采用qemu-kvm加速模块，效果及稳定性更好。

qemu主要有两种主要的模式模式，及用户模式以及系统模式;用户模式即启动模拟平台的软件，系统模式是模拟整个系统平台。

* qemu-img： 创建镜像文件
* qemu-nbd：磁盘挂载工具
* 
* qemu-system-aarch64
*  -M 指定模拟的开发板
