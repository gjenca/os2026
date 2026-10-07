
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {

    int status;
    int pid;
    int fd;

    printf("Hello, world!\n");
    if ((pid = fork())> 0) {
        printf("Parent, child má pid %d\n",pid);        
        wait(&status);
        printf("Child proces skončil exit status=%d\n",WEXITSTATUS(status));
    } else {
        // pid==0
        sleep(1);
        fd=open("etc.txt",O_CREAT|O_WRONLY|O_TRUNC,S_IRUSR|S_IWUSR);
        printf("fd=%d\n",fd);
        dup2(fd,1);
        close(fd);
        execl("/bin/ls","/bin/ls","/etc",NULL);
    }
}
