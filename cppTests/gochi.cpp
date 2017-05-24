#include <iostream>
#include <stdio.h>
#include <cstdlib> // system

using namespace std;

int main()
{
	int x = 5;
	int y = 42;
	cout << "Hello World" << endl;
	std::cout << x << endl;
	std::cout << y << endl;
	int array [3] = {1, 2, 4};
	std::string s = "";
	for(int c = 0; c < 3; c++)
	{
		std::string n = sprintf((char*)array[c]);
		s = s + " " + n + '\n';
	}
	cout << s << endl;

	return 0;
}
