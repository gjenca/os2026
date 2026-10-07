

#include <unistd.h>
#include <stdio.h>

int main() {

    int pipefd[2];
    char buf[50];
    int read_num;

    pipe(pipefd);
    write(pipefd[1],"kapybara",8);
    read_num=read(pipefd[0],buf,49);
    buf[read_num]=0;
    printf("<%s>\n",buf);

}


