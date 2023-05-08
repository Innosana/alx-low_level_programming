/**
 * read_file - Reads a text file and prints it to POSIX stdout.
 * @file_name: A pointer to the name of the file.
 * @num_letters: The number of letters the
 *               function should read and print.
 *
 * Return: If the function fails or file_name is NULL - 0.
 *         O/w - the actual number of bytes the function can read and print.
 */
ssize_t read_file(const char *file_name, size_t num_letters)
{
    ssize_t file_descriptor, num_bytes_read, num_bytes_written;
    char *file_content;

    if (file_name == NULL)
        return (0);

    file_content = malloc(sizeof(char) * num_letters);
    if (file_content == NULL)
        return (0);

    file_descriptor = open(file_name, O_RDONLY);
    num_bytes_read = read(file_descriptor, file_content, num_letters);
    num_bytes_written = write(STDOUT_FILENO, file_content, num_bytes_read);

    if (file_descriptor == -1 || num_bytes_read == -1 || num_bytes_written == -1 || num_bytes_written != num_bytes_read)
    {
        free(file_content);
        return (0);
    }

    free(file_content);
    close(file_descriptor);

    return (num_bytes_written);
}
