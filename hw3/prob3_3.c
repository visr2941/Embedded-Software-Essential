#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char reverse(char * str, int length)
{
        char temp;
        int i = 0;
        for (i=0; i<(length/2);i++)
        {
            temp = *(str+i);
            *(str+i) = *(str+length-i-1);
            *(str+length-1-i) = temp;
        }
        return 0;
}

int main(void)
{
	int i;
	char str1[] = "This is a string.";
	char str2[] = "some NUMmbers12345";
	char str3[] = "Does it reverse \n\0\t correctly?";

	printf("%s\n", str3);	
	//reverse(str1, 17);
	//reverse(str2, 18);
	reverse(str3, 30);

	//printf("reversed string_1 is: %s\n", str1);
	//printf("reversed string_2 is: %s\n", str2);
	printf("reversed string_3 is: %s\n", str3);
	for(i=0; i<30; i++)
		printf("%c", *(str3+i));
	printf("\n");
}

