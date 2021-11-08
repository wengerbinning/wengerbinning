## 指针

指针是一类专门存储内存地址的数据对象，该数据对象的赋值只能是与声明相同数据类型对象的内存地址或者NULL；在指针中有一类特殊的应用，例如函数指针、二维指针等。以下是常用指针的说明。

* 函数指针：指针指向的数据对象是一个函数。
* 数组指针：指针指向的数据对象是一个数组。
* 二维指针：指针指向的数据对象是一个指针。

calloc与malloc以及realloc的辨析：

* void* malloc(unsigned size): 用于申请固定size字节的连续内存空间。不会初始化为零值。返回是一个对象。
* void* calloc(unsigned n, unsigned size): 用于申请n个固定size字节的连续内存空间。在分配时初始化为零值。返回是一个数组。
* void* realloc(void *p, unsigned size): 将指针p指向的内存改为size.

