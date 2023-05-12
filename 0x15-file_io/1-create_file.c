#include "main.h"

/**
 * create_file - creates a file
 * @new_filename: new filename.
 * @new_text_content: new content written in the file.
 *
 * Return: 1 if it succeeds, -1 if it fails.
 */
int create_file(const char *new_filename, char *new_text_content)
{
	int file_descriptor;
	int num_letters;
	int write_result;

	if (!new_filename)
		return (-1);

	file_descriptor = open(new_filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (file_descriptor == -1)
		return (-1);

	if (!new_text_content)
		new_text_content = "";

	for (num_letters = 0; new_text_content[num_letters]; num_letters++)
		;

	write_result = write(file_descriptor, new_text_content, num_letters);

	if (write_result == -1)
		return (-1);

	close(file_descriptor);

	return (1);
}
