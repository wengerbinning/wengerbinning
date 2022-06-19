U-boot项目说明，在2010.06之后的项目有

* `arch/`与硬件平台以及处理器相关的功能。
* `board/`目标板相关的东西，包含SDRAM、FLASH驱动。
* `driver/`通用设备驱动，例如CFI、FLASH等。
* `doc/`说明文档。
* `example/`示例程序。
* `include/`头文件，configs子目录下与目标板相关的配置文件。
* `net/`与网络相关的文件目录。
* `post/`上电自检相关。
* `tools/`构建项目相关工具。

u-boot有两种工作模式：启动加载与下载。


大多数bootloader都分为stage1与stage2，u-boot也不例外，依赖于CPU体系的部分在stage1中并可用汇编来实现，stage2通常为C语言，基本与CPU无关的代码。


