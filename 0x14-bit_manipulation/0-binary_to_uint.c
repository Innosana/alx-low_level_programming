#include "main.h"
#include <stdio.h>

/**
 * binary_to_uint - convert a binary number to an unsigned int.
 * @b: char string.
 * Return: ic.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int ic;
	int len, base_two;

	if (!b)
		return (0);

	ic = 0;

	for (len = 0; b[len] != '\0'; len++)
		;

	for (len--, base_two = 1; len >= 0; len--, base_two *= 2)
	{
		if (b[len] != '0' && b[len] != '1')
		{
			return (0);
		}

		if (b[len] & 1)
		{
		ic += base_two;
		}
	}

	return (ic);
}
