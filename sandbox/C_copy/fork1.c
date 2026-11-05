
#include <unistd.h>
#include <stdio.h>

int main() {

    int pid;

    printf("Hello, world!\n");
    pid=fork();
    if (pid > 0) {
        printf("Parent, child má pid %d\n",pid);    } else {
        // pid==0
        printf("Child\n");
    }
}
