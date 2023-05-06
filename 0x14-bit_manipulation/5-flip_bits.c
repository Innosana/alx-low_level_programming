#include "main.h"
#include <stdio.h>

/**
 * flip_bits - flip bits to convert one number to another number
 * @num1: first number
 * @num2: second number to convert to
 * Return: number of bits that were needed to flip
 */
unsigned int flip_bits(unsigned long int num1, unsigned long int num2)
{
	unsigned long int diff;
	int counter;

	diff = num1 ^ num2;
	counter = 0;

	while (diff)
	{
		counter++;
		diff &= (diff - 1);
	}

	return (counter);
}
