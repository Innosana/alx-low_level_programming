#include <stdio.h>

/**
 * set_bit - sets the value of a bit to 1 at a given index
 * @num: pointer to an unsigned long integer
 * @idx: index position to set the bit, starting from 0
 * Return: 1 if it worked, -1 if error
 */
int set_bit(unsigned long int *num, unsigned int idx)
{
	unsigned long int power;

	if (idx > 63)
		return (-1);

	for (power = 1; idx > 0; idx--, power *= 2)
		;
	*num += power;

	return (1);
}
