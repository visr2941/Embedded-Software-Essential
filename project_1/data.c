#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int8_t * my_itoa(int8_t * str, int32_t data, int32_t base)
{
	int8_t sign=1, val, count=0, i=0, temp;	// defining local variables
	int8_t * str_ret = str; 		// defining a pointer 
	if(base==10|| base == 16)	// checking for base: it can't be other than 10 or 16
		;
	else
	{
		return(NULL);		// return null if base is invalid
	}

	if(data < 0)			// for negative integer or hex, change sign to -1 and make data positive
	{
		sign = -1;
		data = -data;	
	}
	

	// based on the base value, relevant logic to convert 
	// into string is below
	if(base==10)			// for base == 10
	{	
		do	// run atleast once (corner case when data = 0)
		{
			val = data % 10;	// getting the least place digit
			data = data/10;		// removing the last place digit
			*str++ = val + '0';	// storing the charcater value of that digit
			count++;		// increase the counter
		} while(data !=0);
	}
	else if (base==16)	// if base==16
	{
		do	// run atleast once (corner case when data = 0)
		{
			val = data % 16;	// getting the least place digit (base 16)
			data = data /16;	// removing the last place digit
			if(val>=0 && val <= 9) 	// if the digit is numeric, add the '0'
				*str++ = val + '0';
			else if(val >=10 && val <= 15) // if digit is alphabet, add the offset to get the character value
				*str++ = val + 'A' - 10;
			count++;
		} while(data!=0);
	}
	// end of converting int/hex to string
	

	if(sign < 0)		// if sign is less than zero, add a '-' at the end of string
	{
		*str++ = '-';
		count++;
	}	
	*str = '\0';		// end the string with '\0'
	

	// reversing the string
	count = count/2;	// make count equal to it's half to reverse the string
	while(count--)		// based on counting, reverse the string
	{
		temp = *(--str);
		*str = *(str_ret+i);
		*(str_ret+i) = temp;
		i++;
	} // end of string reversal
	
	return str_ret;	// return the pointer to the string
}

void main()
{
	int32_t x = 00; 
	int8_t test[10];
	my_itoa(test, x, 16);
	printf("%s\n", test);
}
