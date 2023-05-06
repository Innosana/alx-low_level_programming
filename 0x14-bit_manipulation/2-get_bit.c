#include "main.h"
#include <stdio.h>

/**
 * get_bit - get the value of a bit at a given index
 * @num: number to evaluate
 * @pos: index starting from 0, of the bit we want to get
 * Return: Value of bit at pos, or -1 if error
 */
int get_bit(unsigned long int num, unsigned int pos)
{
    unsigned long int temp;

    if (pos > 64)
        return (-1);

    temp = num >> pos;

    return (temp & 1);
}
