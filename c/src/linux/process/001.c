#include <stdio.h>
// #include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void main(int agrc, char *argv[]) {
    
    pid_t ppid, pid, spid;
    pid = getpid();
    pid = fork();
    spid = getpid();
    ppid = getppid();
    printf("%d -> %d\n", spid, ppid);
    int a;
    scanf("%d", &a);
}
