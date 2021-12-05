unistd

exec系列函数实现来使用程序文件替换当今进程的任务的功能。

* `int execv(const char *path, char *const argv[]);`

  使用可执行程序文件替换当前进程的程序，第一个参数是一个可执行程序的路径，第二个参数是一个元素为char类型指针的数组常量，其中最后一位元素须为一个空
  指针。进程的环境变量会保留。
  
```c
extern int execv (const char *__path, char *const __argv[]) __THROW __nonnull ((1, 2));
```

* `int execve(const char *path, char *const argv[], char *const envp[]);`

  使用可执行程序文件替换当前进程的程序，与execv的区别是增加了一个环境变量的参数。

```c
extern int execve (const char *__path, char *const __argv[], char *const __envp[]) __THROW __nonnull ((1, 2));
```

* `int execl (const char *path, const char *arg, ...);`

  使用可执行程序文件替换当前进程的程序,与execv的区别在于参数。
  
* `fexecve`
* `execle`
* `execvp`
* `execlp`
* `execvpe`


fork系列函数实现来创建子进程的功能。即对当前进程做一份拷贝。

* `fork`
* `vfork`

fork是创建一个与父进程几乎一样的新进程，之后继续执行下面的指令，根据fork的返回值可以决定当前所在进程，当返回值为0时表示当前进程为子进程，在父进程
中会返回子进程的进程ID


