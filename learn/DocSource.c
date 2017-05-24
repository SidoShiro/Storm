#include <stdio.h>
#include <limits.h> 
#include <float.h>

#define LIM 23

int main()
{
	// Types
	int x = 42; // 32 bit integer
	char* str = "String"; // String
	float f = 99.98; // Float IEEE
	char c = 'f'; // char
	unsigned char uc;
	short s;
	unsigned short us;
	unsigned i; // 32bit integer unsigned
    long l;
	unsigned long ul;	
	double d;
	long double ld;
	const int ci;

	// pointers & Array
	int var;
	var = 20;
	int *refvar;
	refvar = &var;

	// Structures
	struct person
   	{
		int age;
		char* name;
		float balance;
		int happiness;
	};
	
	// Max Types Variables
	unsigned long long ullmax = ULLONG_MAX;
	long lmax = LONG_MAX;
	long double ldmax = LDBL_MAX;
	int ilmax = INT_MAX;
	short slmax = SHRT_MAX;

	printf("The max value of an unsigned long long is %Lu.\n", ullmax);
	printf("The max value of a long is %ld.\n", lmax);
	printf("The max value of a long double is %Lf.\n", ldmax);

	// Arithmetic operators +, -, *, /, %
	// Boolean op >, >=, <=, <, ==, !=
	// Cast  (new*type)variablename;
	// ++ increment, -- decrement
	// Bitwise op : & AND, | OR, ^ XOR, << left shift, >> right shift, - one's complement
		
	// Flow control && if/else if/else
	int age;
	printf("Hello, please enter your age!, \n");
	scanf("%d", &age);
	if(age < LIM)
	{
		printf("Your age is %d.\n", age);
		printf("You are very young !!!");
	}
	else if(age == LIM)
	{
		printf("Your age is %d.\n", age);
        printf("You young just !!!");
	}
	else
	{
		printf("Your age is %d.\n", age);
		printf("Time to find a wife :D !!!");
	}

	// While & For

	return 0;
}

// Functions
int sumint(int a, int b)
{
	return a + b;
}

float sumfloat(float a, float b)
{
	return a + b;
}

