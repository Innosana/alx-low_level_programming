#include <stdio.h>
#include "main.h"

/**
 * main - print _putchar
 * The character to print
 *
 * Return: On success 1.
 */

int main(void)
{
char *word = "_putchar\n";
while (*word)
{
_putchar(*word);
word++;
}
return (0);
}
