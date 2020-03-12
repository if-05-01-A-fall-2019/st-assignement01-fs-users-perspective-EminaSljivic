#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFERSIZE 256

int main(int argc, char *argv[]) {
    if(argc!=3){
        printf("You can only call cpf with two arguments!");
        return 0;
    }
    int ogFile = open(argv[1],O_RDONLY);
    int cpFile = open(argv[2],O_WRONLY | O_CREAT);

    char buffer[BUFFERSIZE];

    int count = read(ogFile, buffer, 256);
    write(cpFile, buffer, count);

    return 0;
}
