#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char* argv[])
{
	FILE* logfile = fopen("log", "a+");
	if(!logfile)
	{
		perror("fopen failed !!!");
		return EXIT_FAILURE;
	}
	for(int i = 1; i < argc; i++)
	{
		fputs(argv[i], logfile);
		fputs("\n", logfile);
	}
	
	return EXIT_SUCCESS;
}
