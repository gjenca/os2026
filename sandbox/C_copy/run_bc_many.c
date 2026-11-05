#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {

    FILE *vyrazy;
    FILE *vysledky;
    int pipefd_A[2];
    int pipefd_B[2];
    char buf[50];
    int status;
    int vysledok;
    int pid;
    int n;

    pipe(pipefd_A);
    pipe(pipefd_B);
    if ((pid = fork())> 0) {
        close(pipefd_A[1]);
        close(pipefd_B[0]);
        vyrazy=fdopen(pipefd_B[1],"w");
        vysledky=fdopen(pipefd_A[0],"r");
        for (n=0;n<11;n++) {
            fprintf(vyrazy,"7*%d\n",n);
        }
        fflush(vyrazy);
        fclose(vyrazy);
        //close(pipefd_B[1]); sa udeje automaticky
        while (!feof(vysledky)) {    
            fscanf(vysledky,"%d",&vysledok);
            printf("%d\n",vysledok);
        }
    } else {
        close(pipefd_A[0]);
        close(pipefd_B[1]);
        dup2(pipefd_B[0],0);
        dup2(pipefd_A[1],1);
        execl("/bin/bc","/bin/bc",NULL);
    }
}
