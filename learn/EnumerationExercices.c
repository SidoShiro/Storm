#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	enum corvid {magpie, raven, jay, chough, corvid_num, };
	char const*const animal[corvid_num] = {
		 [chough] = "chough",
		 [raven] = "raven", 
		 [magpie] = "magpie",
		 [jay] = "jay",
	};

	for(unsigned i = 0; i < corvid_num; ++i)
	{
		printf("Corvid %u is the %s\n", i, animal[i]);
	}

}
