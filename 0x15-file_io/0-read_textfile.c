#include "main.h"

/**
 * read_and_print_text - reads a text file and prints the characters
 * @filename: filename.
 * @max_chars: maximum number of characters to print.
 *
 * Return: number of characters printed. If it fails, returns 0.
 */
ssize_t read_and_print_text(const char *filename, size_t max_chars)
{
	int file_descriptor;
	ssize_t num_chars_read, num_chars_written;
	char *buffer;

	if (!filename)
		return (0);

	file_descriptor = open(filename, O_RDONLY);

	if (file_descriptor == -1)
		return (0);

	buffer = malloc(sizeof(char) * max_chars);
	if (!buffer)
		return (0);

	num_chars_read = read(file_descriptor, buffer, max_chars);
	num_chars_written = write(STDOUT_FILENO, buffer, num_chars_read);

	close(file_descriptor);

	free(buffer);

	return (num_chars_written);
}
