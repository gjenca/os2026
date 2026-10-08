
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {

    int pipefd[2];
    char buf[50];
    int read_num;
    int status;
    int pid;

    pipe(pipefd);
    if ((pid = fork())> 0) {
        close(pipefd[1]); // Zavrieme zapisovy koniec pipe
        printf("Parent, child má pid %d\n",pid);
        // read vracia pocet bytov precitanych, 0 ak je EOF
        // EOF pre pipe <=> ziadny proces nema otvoreny zapisovy koniec pipe
        // a vsetko sa uz precitalo
        while(read_num=read(pipefd[0],buf,sizeof(buf))) {
            write(1,buf,read_num);
            write(1,"BUM\n",4);
        }
        wait(&status);
    } else {
        close(pipefd[0]); // Citavy koniec rury child proces nepotrebuje
        dup2(pipefd[1],1);
        close(pipefd[1]); // pipefd[1] je uz zduplikovane
        execl("/bin/ls","/bin/ls","/etc",NULL);
    }
}
