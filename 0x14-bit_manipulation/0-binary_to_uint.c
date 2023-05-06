#include "main.h"
#include <stdio.h>

/**
 * binary_to_uint - convert a binary number to an unsigned int
 * @binary: string of binary digits
 *
 * Return: converted decimal number or 0 if there is an unconvertable char
 */
unsigned int binary_to_uint(const char *binary)
{
	unsigned int result = 0, power = 1;
	int length = 0;

	if (binary == NULL)
		return (0);

	for (length = 0; binary[length]; length++)
	{
		if (binary[length] != '0' && binary[length] != '1')
			return (0);
	}

	for (length--; length >= 0; length--, power *= 2)
	{
		if (binary[length] == '1')
			result += power;
	}

	return (result);
}
