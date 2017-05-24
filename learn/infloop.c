#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char* argv[argc+1])
{
	puts("Hello world!");
	if(argc > 1)
	{
		while(true) 
		{
			puts("some programs never stop");
		}
	}
	else
	{
		do
		{
			puts("but this one does");
		}
		while(false);
	}

	return EXIT_SUCCESS;
}

