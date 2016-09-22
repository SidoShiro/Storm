// Prototypes
void parseParam(int count, char* para[]);
int strpara(char* str1, char* str2);
void print(char* str);

// Functions
void parseParam(int count, char* para[])
{
	for(int c = 0; c < count; c++)
	{	
		char* p = para[c];
		if(1 == strpara(p, "--version"))
		{
			print("Storm v0");
		}
		else if(1 == strpara(para[c], "-v"))
		{
			print("Storm v0");
		}
		else if(1 == strpara(p, "-s"))
		{
			c++;
			if(c < count && 1 == strpara(para[c], " "))
			{
				// file detected
				
			}
			else
			{
				print("Error file !");
			}
		}
		else if(1 == strpara(p, "-h"))
		{
			print("storm [-h] : help panel \n      [-v] : version\n      [-s] [filename] : do stuff");
			print("      [--version] : version");
		}
		else if(count == 0)
		{
			print("Option not understand");
		}
	}
}

void print(char* str)
{
	printf("%s\n", str);
}

int strdiff(char* str1, char* str2)
{
	int count = sizeof(str2);
	int ya = 1;
	for(int c = 0; c < count; c++)
	{
		if(str1[c] == str2[c])
		{
			ya = 0;
		}
	}
	return ya;
}

int strpara(char* str1, char* str2)
{
	int count = sizeof(str2);
   	int ya = 1;	
	for(int c = 0; c < count; c++)
	{
		if(str1[c] != str2[c])
		{
			ya = 0;
		}
	}

	return ya;
}
