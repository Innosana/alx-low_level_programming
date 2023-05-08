#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *allocate_buffer(char *filename);
void close_fd(int fd);

int main(int argc, char *argv[])
{
    int input_fd, output_fd, read_bytes, written_bytes;
    char *buffer;

    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s file_from file_to\n", argv[0]);
        exit(97);
    }

    buffer = allocate_buffer(argv[2]);
    input_fd = open(argv[1], O_RDONLY);
    read_bytes = read(input_fd, buffer, 1024);
    output_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

    do {
        if (input_fd == -1 || read_bytes == -1)
        {
            fprintf(stderr, "Error: Can't read from file %s\n", argv[1]);
            free(buffer);
            exit(98);
        }

        written_bytes = write(output_fd, buffer, read_bytes);
        if (output_fd == -1 || written_bytes == -1)
        {
            fprintf(stderr, "Error: Can't write to file %s\n", argv[2]);
            free(buffer);
            exit(99);
        }

        read_bytes = read(input_fd, buffer, 1024);
        output_fd = open(argv[2], O_WRONLY | O_APPEND);

    } while (read_bytes > 0);

    free(buffer);
    close_fd(input_fd);
    close_fd(output_fd);

    return (0);
}

char *allocate_buffer(char *filename)
{
    char *buffer;

    buffer = malloc(sizeof(char) * 1024);

    if (buffer == NULL)
    {
        fprintf(stderr, "Error: Can't allocate memory for %s\n", filename);
        exit(99);
    }

    return (buffer);
}

void close_fd(int fd)
{
    int result;

    result = close(fd);

    if (result == -1)
    {
        fprintf(stderr, "Error: Can't close file descriptor %d\n", fd);
        exit(100);
    }
}
