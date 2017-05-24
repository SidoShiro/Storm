#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int len = argc - 1;
	int array[len];
	for(int i = 1; i < len + 1; i++)
	{
		array[i - 1] = atoi(argv[i]);
	}

	// Bubble
	bool swap = false;
	do
	{
		swap = false;
		for(int i = 0; i < len - 1; i++)
		{
			if(array[i] > array[i + 1])
			{
				int tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				swap = true;
			}
		}
	}while(swap);

	printf("Bubble Sorted Array : \n");
	for(int i = 0; i < len; i++)
	{
		printf("index %d : value %d \n", i, array[i]);
	}

	return 0;
}
