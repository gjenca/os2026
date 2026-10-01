#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {

    int fd;
    pid_t pid;
    static char buf[20];
    
    fd=open("subor.txt",O_CREAT|O_WRONLY|O_APPEND,S_IRUSR|S_IWUSR);
    pid=fork();
    printf("fd=%d\n",fd);
    write(fd,"Kapybara\n",9);
    sprintf(buf,"pid=%d\n",pid);
    write(fd,buf,strlen(buf));
    close(fd);
} 
