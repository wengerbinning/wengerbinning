可执行与可链接文件格式(ELF,Executable and Linkable File Format)是一种用于二进制文件的格式，可以用于存储可执行程序、目标代码、共享库、核心转储等。是UNIX系统实验室作为ABI而开发的，是Linux的默认可执行文件格式。常用`*.o`、`*.so`、`*.a`、`*.elf`、`*.prx`作文件标识。

ELF文件由四部分组成ELF头部(ELF header)、程序头表(program header table)、节(section)与节头表(section header table)。文件中不一定同时存在这四部分，其中ELF头部位置固定，其他由部分由头部决定。


ELF头部具有以下属性：
  
  * `e_ident[EI_NIDENT]`
  * `e_type`表示文件类型。
  * `e_machine`表示运行该程序需要的体系结构。
  * `e_version`表示文件的版本。
  * `e_entry`表示程序的入口。
  * `e_phoff`表示程序头部在文件中的偏移量。
  * `e_shoff`表示节头部在文件中的偏移量。
  * `e_flags`
  * `e_ehsize`表示ELF头部的大小。
  * `e_phentsize`表示程序头表中每一条记录的大小。
  * `e_phnum`表示程序头表有多少条记录。
  * `e_shensize`表示节头表每一个记录的大小。
  * `e_shnum`表示节头表有多少条记录。
  * `e_shstrndx`包含节名称的节的索引。

程序头部：


节类型：

* `PROGBITS`
* `DYNSYM`
* `VERSYM`
* `RELA`
* `STRTAB`
* `DYNAMIC`
* `NOBITS`

遇到的一些节

* `.interp` -- `PROGBITS`
* `.hash` -- 	`HASH`
* `.init` -- 	`PROGBITS`
* `.plt`
* `.text`
* `.rodata`
* `.data`
* `.bss`
* `.debug`
* `.line`
* `.rel.text`
* `>rel.data`
* `.symtab`
* `.dynsym`
* `.dynstr`
* `.gnu.version`
* `.gnu.version_r`
* `.rela.dyn`
* `.rela.plt`
* `.fini`
* `.got`
* `.got.plt`
* `.comment`
* `.shstrtab`


 
