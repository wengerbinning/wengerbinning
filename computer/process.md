* 进程的状态

  1. `R (TASK_RUNNING)`进程正在运行。
  2. `S (TASK_INTERRUPTIBLE)`进程处于可中断的睡眠状态，可以被信号中断。唤醒后状态变为`TASK_RUNNING`。
  3. `D (TASK_UNINTERRUPTIBLE)`进程处于不可中断的睡眠状态，不处理信号。
  4. `T (TASK_STOPPED)`进程被中止执行，在接收到SIGSTOP或SIGTSTP等信号，进入这种状态，接收到SIGCOUT后再次运行。
  5. `T (TASK_TRACED)`正被调试或其他进程监控时的状态。
  6. `Z (EXIT_ZOMBIE)`进程处于僵尸状态已终止，向父进程发送SIGCHLD信号，等待父进程收集信息。
  7. `X (EXIT_DEAD)`进程退出运行，父进程收集完信息后进入该状态。
` 
