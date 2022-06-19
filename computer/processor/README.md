处理器(processor)是计算机的核心，是实现控制与计算功能的模块，一般称为中央处理单元(CPU, Central 
Processing Unit)，CPU是集成控制器、运算器以及寄存器的芯片；在实际使用中，也会将其他功能集成到CPU
中，例如AD/DC、射频、通信基带、音视频编解码器等模块；该类芯片被称为片上系统(SOC, System On Chip)，
目的是通过简单的扩展就可以实现一个计算机系统，基于SOC在不同的应用场景，可以分为微处理器(MPU, Micro 
Processing Unit)与微控制器(MCU, Micro Controller Unit)，手机、路由器等产品中的处理器属于
微处理器，偏向于处理任务，智能家电中的为微控制器，偏向于控制任务。在嵌入式邻域，所谓的单片机(SCM, 
Single Chip Microcomputer)是就是基于SOC实现的解决方案。常见的解决方案有手机、路由器等。

在了解处理器之前，我们先了解一下处理器的指令集架构与微架构。

指令集架构(ISA, Instruction Set Architecture)是指包含了一系列操作码以及由特定CPU执行的指令。
常见的指令集架构有复杂指令集运算(CISC, Complex Instruction Set Computing)、精简指令集运算(
RISC, Reduced Instruction Set Computing)、显式并行指令集运算(EPIC, Explicitly Parallel
Instruction Computing)以及超长指令字指令集运算(VLIW)。指令是由运算符(Opcode)与操作数(
Operands)组成，主要有控制指令、数据操作指令以及运算指令。mei

**CISC**

基于CISC的处理器有x86微架构


**RISC**

基于RISC的处理器有arm、mips、alpha微架构


处理器的微架构是指令集架构的实现方案，常见的有x86、arm、mips、alpha等微架构。其中第一款x86的处理
器是Intel与1978年发布的8086，随后又发布了8088、80286等，1999年AMD将x86架构从32位扩展到64位，
称为AMD64，Intel扩展后称为x64或者x86_64，在linux中，将x86称为i386、x86_64称为amd64；1985年，
Acron发布了ARMv1的第一代处理器，2011年，ARMv8将指令集扩展到64位，称为AArch64，之前的称为
AArch32，在linux中AArch32称为arm、AArch64称为aarch64。

**x86**

x86微架构是Intel基于CISC架构实现的方案，可以直接处理存储器中的数据，因此寻址方式更多样：立即寻址、寄存器寻址、直接寻址、
寄存器间接寻址，x86包含8个通用寄器(EAX、EBX、ECX、ESI、EDI、EBP、ESP)， x64扩展到16个寄存器。

**arm**

arm微架构是基于RISC的实现方案，其中ARMv1~7是32位，1999年ARMv8扩展到64位，称为AArch64，之前版
本称为AArch32。

arm拥有31个通用寄存器

**mips**


中央处理单元(CPU, Central Processing Unit)是在一块芯片上集成了控制器、运算器以及寄存器。负责
从内存读取指令并翻译执行的功能。CPU有指令集架构与微架构区别，指令集架构是指CPU实现的指令模型，主要
有CISC与RISC以及RISC-V；微架构是指实现指令集架构的具体电路方案，主流的微架构有x86、arm、mips等。

片上系统(SOC, System On Chip)


处理器生产厂商
===========

**因特尔**

因特尔(Intel)生产的CPU

**AMD**

AMD生产


**苹果**

苹果(Apple)生产的A系列处理器。


**高通**


高通(Qualcomm)生产的骁龙处理器，用于移动平台


**联发科**


联发科(MediaTek)生产的天玑系列处理器，用于移动平台


**华为**


华为(HUAWEI)生产海思麒麟处理器，用于移动平台。



**三星**


三星(SAMSUNG)生产的猎户座处理器



**龙芯**


龙芯


汇编语言
======

**x86的汇编语言**

这个的x86是指x86与x64两种，将x64看作是x86的扩展。x86的汇编有Intel与AT&T两种风格，gcc、gdb、
objdump默认使用AT&T风格。

**arm的汇编语言**


**mips的汇编语言**
