#include "main.h"

/**
 * check_endianness - check endianness of the machine
 *
 * Return: 1 if little-endian, 0 if big-endian
 */
int check_endianness(void)
{
    int value = 1;
    char *ptr = (char *)&value;

    if (*ptr == 1) {
        return 1;
    }
    return 0;
}
