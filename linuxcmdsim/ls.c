#include <stdio.h>
#include <dirent.h>
#include <unistd.h>

int main() {
    
    /* Struct dir name type */
    struct dirent **namelist;
    
    int n = 0;
    int i = 0;
    char pathname[100];

    /* malloc pathname if null, */
    getcwd(pathname, 100);

    for(int k = 0; k < 100; k++)
        printf("%c", pathname[k]);
    printf("\n\n");

    n = scandir(pathname, &namelist, 0, alphasort);

    if(n < 0) {
        perror("scandir");
    }
    else {
        for(i = 0; i < n; i++) {
            if (namelist[i]->d_name[0] != '.') {
                printf("%s\n", namelist[i]->d_name);
            }
        }
    }

    printf("\n");

    return 0;
}
