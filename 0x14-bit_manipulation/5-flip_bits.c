#include "main.h"
#include <stdio.h>

/**
 * flip_bits - calculate the number of bits that need to be flipped in num1 
 *             to obtain num2
 * @num1: the first number
 * @num2: the second number
 * Return: the number of bits that were flipped
 */
unsigned int flip_bits(unsigned long int num1, unsigned long int num2)
{
	unsigned long int diff;
	int counter;

	/* XOR operation to find the bits that are different */
	diff = num1 ^ num2;
	counter = 0;

	/* Count the number of set bits in the XOR result */
	while (diff)
	{
		counter++;
		diff &= (diff - 1);
	}

	return (counter);
}
