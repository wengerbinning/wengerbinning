# 文件系统

文件管理系统是操作系统管理存储设备中的文件的模型，简称文件系统。




```c
// linux/fs.h
struct file_operations {
    struct module *owner;
    loff_t (*llseek) (struct file *, loff_t, int);
    ssize_t (*read) (struct file *, char __user *, size_t, loff_t *);
}
```