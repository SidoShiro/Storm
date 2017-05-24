#include <stdio.h> // printf, scanf, NULL
#include <stdlib.h> // malloc, free, rand

int main()
{
	int i;
    int n = 0;
	char* buff;

	printf("Test Malloc !\n give a size ?\n >>> ");
	scanf("%d", &i);
	
		buff = (char*) malloc (i+1);
		if(buff == NULL) exit (1);

		for(n = 0; n < i; n++)
		{
			buff[n] = rand() % 26 + ' ';
		}
		buff[i] = '\0';

	printf("Rand string :: %s \n", buff);
	
	free(buff);

	return 0;
}	

