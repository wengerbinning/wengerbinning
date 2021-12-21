#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int g_var;

enum pip_direction {
    OUT,
    IN,
};

int main(int argc, const char *argv[]) {
    int pipefd[2];
    pid_t pid;
    char buffer[1024];
    int len;

    printf("[DEBUG](%d) host task is runing ...\n", getpid());

    // Open a pipe from pipefd[1] to pipefd[0].
    if ( pipe(pipefd) ) {
        printf("[ERROR](%d) pipe open error!\n", getpid());
        return -1;
    }

    printf("[DEBUG](%d) create a pipe from %d to %d.\n", getpid(), pipefd[IN], pipefd[OUT]);

    // write(STDOUT_FILENO, buffer, sizeof(buffer));
    // printf("%s@",buffer);

    pid = vfork();
    if(pid == -1) {
        printf("[ERROR](%d) vfork is error!\n", getpid());
        return -1;
    } else if (pid == 0) {
        close(pipefd[OUT]);
        dup2(pipefd[IN],1);
        close(pipefd[IN]);
        close(0); close(2);
        write(pipefd[IN], "hello, I am Clark!", 20);
        execl("/usr/sbin/tcpdump", "/usr/sbin/tcpdump","--immediate-mode", "-w", "-", NULL);
    } else {
        close(pipefd[IN]);
        printf("[DEBUG](%d) vfork sub task is %d.\n", getpid(), pid);
    
        while (read(pipefd[OUT],buffer,sizeof(buffer)) > 0 )
        {
            printf("%s--->",buffer);
        }

        printf("[DEBUG](%d) len is %d and pipe is close!\n",getpid(), len);    

        waitpid(pid, NULL, 0);
        printf("[DEBUG](%d) child process %d had exit.\n", getpid(), pid);
    }
    return 0;
}
