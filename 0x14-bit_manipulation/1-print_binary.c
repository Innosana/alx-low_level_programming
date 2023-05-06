#include "main.h"
#include <stdio.h>

/**
 * my_print_binary - print binary representation of a number
 * @input_num: decimal number to print as binary
 */
void my_print_binary(unsigned long int input_num)
{
	unsigned long int temp_num;
	int num_shifts;

	if (input_num == 0)
	{
		printf("0");
		return;
	}

	for (temp_num = input_num, num_shifts = 0; (temp_num >>= 1) > 0; num_shifts++)
		;

	for (; num_shifts >= 0; num_shifts--)
	{
		if ((input_num >> num_shifts) & 1)
			printf("1");
		else
			printf("0");
	}
}
