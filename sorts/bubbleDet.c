#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));

	int swapping = 0;
	int loop = 0;

	int len = 64880;
	int array[len];
	for(int i = 1; i < len + 1; i++)
	{
		array[i - 1] = (int) rand();
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
				swapping++;
			}
		}
		loop++;
	}while(swap);

	printf("Bubble Sorted Array : \n");
	printf("Test Results : Elements : %d -- Swapping : %d -- Loops : %d \n", len, swapping, loop);
	for(int i = 0; i < len; i++)
	{
		printf("index %d : value %d \n", i, array[i]);
	}

	return 0;
}
