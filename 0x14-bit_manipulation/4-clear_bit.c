#include "main.h"
#include <stdio.h>

/**
 * clear_bit - sets the value of a bit to 0 at a given index
 * @num_ptr: pointer to the decimal number to modify
 * @index: index position of the bit to change
 *
 * Return: 1 if the bit was successfully set to 0, or -1 if there's an error
 */
int clear_bit(unsigned long int *num_ptr, unsigned int index)
{
	unsigned long int i;
	unsigned int count;

	/* Check if the index is valid */
	if (index > 64)
		return (-1);

	/* Count from 0 to index to create a mask */
	count = index;
	for (i = 1; count > 0; i *= 2, count--)
		;

	/* If the bit is already 0, no need to change it */
	if ((*num_ptr >> index) & 1)
		*num_ptr -= i;

	return (1);
}
