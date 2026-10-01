
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {

    int status;
    int pid;

    printf("Hello, world!\n");
    if ((pid = fork())> 0) {
        printf("Parent, child má pid %d\n",pid);        wait(&status);
        printf("Child proces skončil exit status=%d\n",WEXITSTATUS(status));
    } else {
        // pid==0
        sleep(1);
        execl("/bin/ls","/bin/ls","/neexistuje",NULL);
    }
}
