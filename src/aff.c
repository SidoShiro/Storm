# include <stdlib.h>
# include <stdio.h>



void loadscreen(char* mat, size_t i, size_t j)
{
    char* s = "";
    for(size_t m = 0; m < i; m++)
    {
        for(size_t n = 0; n < j; n++)
            s += mat[m * j + n];
        s += '\n';
    }
    printf("%s", s);
}



