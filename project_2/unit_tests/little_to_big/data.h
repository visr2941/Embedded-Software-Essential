#ifndef __DATA_H
#define __DATA_H
/***************************************************************************
*	
*	my_itoa():
*		description: 
*			to covert int or hex into string of
*			chracters.
*		params: 
*			int8_t * str: the pointer of array passed 
*				      to get the string output
*			int32_t data: 32-bit integer data input
*			int32_t base: base of the integer i.e base10
*				      or base16
*		return: 
*			int8_t *: pointer to the string or NULL pointer
*				  if the base is not 10 or 16
*
*	my_atoi()
*		description: 
*			to convert the string of digits into interger 
*		params:
*			int8_t * str: the pointer of the string
*		return:
*			int32_t: return the integer value of the string
*				 of digits
*	
*	big_to_little32()
*		description:
*			to convert big-endian to little endian; function
*			takes a pointer and length of uint32_t data
*		params:
*			uint32 * data: pointer to a uint32_t data type
*			uint32_t length: lenght of data of type uint32_t 
*		return: returns the status of pass/fail
*	
*	little_to_big32()
*		description:
*			to convert little-endian to big endian; function
*			takes a pointer and length of uint32_t data
*		params:
*			uint32 * data: pointer to a uint32_t data type
*			uint32_t length: lenght of data of type uint32_t 
*		return: returns the status of pass/fail
*
*	void print_memory()
*		description:
*			to print the memory content
*		params:
*			uint8_t * start: pointer to a uint8_t data 
*			uint32_t length: length of uint32_t data to print
*		return void
*
****************************************************************************/
typedef enum status {SUCCESS, FAIL} status_e;

int8_t * my_itoa(int8_t * str, int32_t data, int32_t base);
int32_t my_atoi(int8_t * str);
status_e big_to_little32(uint32_t * data, uint32_t length);
status_e little_to_big32(uint32_t * data, uint32_t length);
void print_memory(uint8_t * start, uint32_t length);

#endif // end of __DATA_H
