# 文件系统

文件管理系统是操作系统管理存储设备中的文件的模型，简称文件系统。在Linux中，通过VFS层来讲所有的文件系统进行封装，为上层提供一个统一的接口
来管理文件，在Linux中，有三大类文件系统：基于非易失性的存储介质的文件系统：ext4、resisterfs、fat、ubifs、yaff2等，虚拟文件系统（这个
概念与上面的VFS有所不同，这里的虚拟文件系统是指不存储在非易失的存储介质上，而是在内存中动态生成的；之前的VFS是对所有的文件进行封装的抽象层）
：procfs、sysfs等以及网络文件系统：NTFS、CIFS等。


```c
// linux/fs.h
struct file_operations {
    struct module *owner;
    loff_t (*llseek) (struct file *, loff_t, int);
    ssize_t (*read) (struct file *, char __user *, size_t, loff_t *);
}
```