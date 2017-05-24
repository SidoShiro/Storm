// Cocktail Sort Program, takes 'int' arguments for sorting			   
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <time.h>

int sum(int a, int b);

// NOOOOO Take args in program parameter then print sorting 
int main()
{
	srand(time(NULL)); // Seed Rand

	// Testing Vars
	int swapping = 0;
	int loop = 0;
			
	int len = 64880;
	int array [len - 1];
	for(int i = 1; i < len; i++)
	{
		array[i - 1] = (int) rand(); // Convert char* to int32 
	}
	bool swapped = false;
	bool isLoop = true;
	do
	{
 		swapped = false;
		for(int i = 0; i < len - 3; i++)
		{
			if(array[i] > array[i + 1])
			{

				int tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				swapped = true;
				swapping++;
			}	
		}	
		if(false == swapped) // Exit loop, sorting success
		{
			isLoop = false;
		}
		else
		{
			swapped = false;
			for(int i = len - 3; i > 0; i--)
			{
				if(array[i] > array[i + 1])
				{
					int tmp = array[i];
					array[i] = array[i  + 1];
					array[i + 1] = tmp;
					swapped = true;
				}
			}
		}
		loop++;
	} while (swapped && isLoop);
	
	printf("Cocktail Sorted Array\n");
	printf(" Test Results : Elements : %d -- Swappings : %d -- Loops : %d  \n", len, swapping, loop);
	for(int i = 0; i < len - 1; i++)
	{
		printf("index : %d | value : %d \n", i, array[i]);
	}

	return 0;
} 

int sum(int a, int b)
{
	return a + b;
}
