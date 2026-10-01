#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {

    int fd;
    
    fd=open("subor.txt",O_CREAT|O_WRONLY|O_TRUNC,S_IRUSR|S_IWUSR);
    printf("fd=%d\n",fd);
    write(fd,"Kapybara\n",9);
    close(fd);
} 
