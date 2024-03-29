#include "main.h"

/**
 * set_bit - Sets the value of a bit to 1 at a given index
 * @n: Pointer to an unsigned long int
 * @index: Index of the bit
 *
 * Return: 1 if it worked, -1 if it didn't
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > sizeof(unsigned long int) * 8 - 1)
		return (-1);

	*n |= (1 << index);

	return (1);
}
