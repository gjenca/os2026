#include <unistd.h>
#include <stdio.h>

int main() {

    printf("Končíme\n");
    execl("/bin/ls","/bin/ls",".",NULL);
    printf("Toto sa nevypíše\n");
}

