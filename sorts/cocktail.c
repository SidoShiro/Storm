// Cocktail Sort Program, takes 'int' arguments for sorting			   
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 

void sum(int a, int b);

// Take args in program parameter then print sorting 
int main(int argc, char* argv[])
{
	int len = argc;
	int array [len - 1];
	for(int i = 1; i < len; i++)
	{
		array[i - 1] = atoi(argv[i]); // Convert char* to int32 
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
	} while (swapped && isLoop);
	
	printf("Cocktail Sorted Array\n");
	for(int i = 0; i < len - 1; i++)
	{
		printf("index : %d | value : %d \n", i, array[i]);
	}

	return 0;
} 

void sum(int a, int b)
{
	return a + b;
}
