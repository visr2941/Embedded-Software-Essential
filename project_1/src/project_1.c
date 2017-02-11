#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void project_1_report(void)
{
	uint8_t i = 0, j = 0;
	uint8_t arr1[32], arr2[32], arr3[32];
	for (i; i<sizeof(arr1); i++)
	{
		if(i>9)
			arr1[i] = j++;
		else
			arr1[i] = i;
	}

	for (i=0; i<sizeof(arr2); i++)
        {       
                arr2[i] = i;
        }

	for(i=0, j=0; i<sizeof(arr3); i++)
	{
		if(i<26)
			arr3[i] = 97+i;
		else
			arr3[i] = 65+j;
	}
}


main()
{
	project_1_report();
}
