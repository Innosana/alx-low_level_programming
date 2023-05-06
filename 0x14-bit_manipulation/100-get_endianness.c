#include "main.h"

/**
 * check_endianness - Checks the endianness of the machine.
 *
 * This function checks the endianness of the machine it's running on
 * by checking the value of a 4-byte integer.
 *
 * Return: 1 if the machine is little-endian, or 0 if it's big-endian.
 */
int check_endianness(void)
{
    int value = 1;
    char *ptr = (char *)&value;

    if (*ptr == 1) {
        return 1; // machine is little-endian
    }
    return 0; // machine is big-endian
}
