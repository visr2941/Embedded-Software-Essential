#include "data.h"

int8_t * my_itoa(int8_t * str, int32_t data, int32_t base)
{
	int8_t sign=1, val, count=0, i=0, temp, j = 0;	// defining local variables
	

	if(base>2 || base<=16)	// checking for base: it can't be other than 10 or 16
		;
	else
	{
		printf("hello\n");
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
			*(str+i++) = val + '0';	// storing the charcater value of that digit
			count++;		// increase the counter
		} while(data !=0);
	}
	else if (base==16)	// if base==16
	{
		do	// run atleast once (corner case when data = 0)
		{
			val = data % base;	// getting the least place digit (base 16)
			data = data / base;	// removing the last place digit
			if(val>=0 && val <= 9) 	// if the digit is numeric, add the '0'
				*(str+i++) = val + '0';
			else if(val >=10 && val <= 15) // if digit is alphabet, add the offset to get the character value
				*(str+i++) = val + 'A' - 10;
			count++;
		} while(data!=0);
	}
	// end of converting int/hex to string

	if(sign < 0)		// if sign is less than zero, add a '-' at the end of string
	{
		*(str+i++) = '-';
		count++;
	}	
	*(str+i) = '\0';		// end the string with '\0'


	// reversing the string
	i = count/2;	// make count equal to it's half to reverse the string
	while(i)		// based on counting, reverse the string
	{
		temp = *(str+count-j-1);
		*(str+count-1-j)=*(str+j);
		*(str+j) = temp;
		i--;
		j++;
	} // end of string reversal

	
	return str;	// return the pointer to the string
} // end of the my_itoa function



int32_t my_atoi(int8_t * str)
{
	int32_t val=0;  	// integer value to be returned
	int8_t sign=1;		// determining the sign
	if(*str=='-')		// if first character of string is "-"
	{	
		sign = -1;	// change sign to -1
		str++;
	}
	
	while(*str!='\0')	// loop till the end of string
	{
		if(*str <= '0' || *str >= '9')	// if character is not digit kind
			return(val*sign);	// return the val before that non-digit char
		val = 10*val + *str++-'0';	// calculate the integer value of string
	}
	return (val*sign);	// return the intger value
} // end of my_atoi function



/*status_e big_to_little32(uint32_t * data, uint32_t length)
{
	uint32_t temp=0;	// temporary variable
        uint8_t i;		// loop variable
	if(data==NULL)
		FAIL;
        while(length--)		// loop to change endian-ness of all the elements
        {

                i = 7;		// lopp variable value to 7 to change nibble
                while(i--)
                {
                        temp |= (*data & 0xF);		// taking out last nibble of the data
                        *data = *data >>4;		// left shift data by 4 to take out the next nibble
                        temp = i ? temp<<4: (temp<<4 | *data);	// in the last loop, temp is shifted and ORed with *data
                }
                *data++ = temp;		// transferring the temp value to data (swapping)
                temp = 0;		// initilaizing temp again to zero
        }
        return SUCCESS;
} // end of big_to_little32 function 



// the below function little_to_big32 is same as big_to_little32 as defined above
status_e little_to_big32(uint32_t * data, uint32_t length)
{	
	uint32_t temp=0;
	uint8_t i;
	if(data==NULL)
		FAIL;
	while(length--)
	{
		i = 7;
		while(i--)	
		{
			temp |= (*data & 0xF);
			*data = *data >>4;
			temp = i ? temp<<4: (temp<<4 | *data);
		}
		*data++ = temp;
		temp = 0;
	}
	return SUCCESS;
} // end of the little_to_big32 


void print_memory(uint8_t * start, uint32_t length)
{
	while(length--)		// looping for the length of data
	{
		printf("0x%X ", *start++); 	// printing the memory
	}
	printf("\n");
	return;
} // end of printf_memory function*/
