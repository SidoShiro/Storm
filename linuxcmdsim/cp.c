#include <fcntl.h> /* Manipulate file descriptor */
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#define SIZE 1024

int main(int argc, char * argv[]) {
    int source, destination, nread;
    char buffer[ SIZE ];
    
    if(argc != 3) {
        printf("Argument Error ! \n");
        printf(" Argument Required : \n");
        printf("  Filename\n  NewFile\n");
        exit(-1);
    }

    if((source = open(argv[1], O_RDONLY)) == -1) {
        perror(argv[1]);
        exit(-1);
    }
    if((destination = creat(argv[2], 0644)) == -1) {
        perror(argv[1]);
        exit(-1);
    }

    while((nread = read(source, buffer, SIZE)) > 0) {
        if (write(destination, buffer, nread) == -1) {
            printf("Can't write !\n");
            exit(-1);
        }
    }

    close(source);
    close(destination);

    return 0;
}


