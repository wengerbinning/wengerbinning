#include<sys/types.h>
#include<unistd.h>
int main() {
    int prepid, pid, ppid;
    prepid = pid = ppid = 0;
    prepid = getpid();
    prinf("Pre PID: %d\n", prepid);
    pid = fork();
    // pid = getpid();
    // ppid = getppid();
    // printf("PID: %d, PPID: %d \n", pid, ppid);
    printf("PID: %d\n", pid);
    return 0;
}