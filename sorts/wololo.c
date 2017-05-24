#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[])
{
    srand(time(NULL));

    int len = argc - 1;
	int array[len];
	for(int i = 1; i < len + 1; i++)
	{
		array[i - 1] = atoi(argv[i]);
	}
 
    int status = 0;
    
        for(int i = 0; i < len; i++)
            array[i] = (short) rand();

    printf("Wololo is very dangerous ! The data has been purified !\n");
    printf("Sorting... Wololo !\n");
    printf("Results :\n\n Wololo !!! \n\n");

    for(int i = 0; i < len; i++)
	{
		printf("index %d : value %d \n", i, array[i]);
	}

	return 0;
}
