# 数组

数组是同一种数据类型的数据集合，一般在数据区或者栈区，其大小与元素的数据类型在程序运行期间不可改变，





**结构体数组**

```c
// struct array students[40].
struct {
    char name[16];
    char sex[2];
    int age;
    char addr[40];
} students[40];
```

