#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    // Test 1: Basic test with a file containing multiple lines
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening file!\n");
        return (1);
    }
    printf("Test 1: Reading from test.txt\n");
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);

    // Test 2: Empty file
    fd = open("empty.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening file!\n");
        return (1);
    }
    printf("\nTest 2: Reading from empty.txt\n");
    line = get_next_line(fd);
    if (line == NULL)
        printf("Empty file handled correctly.\n");
    else
        printf("Error: Expected NULL, got %s\n", line);
    close(fd);

    // Test 3: Single line without newline
    fd = open("single_line.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening file!\n");
        return (1);
    }
    printf("\nTest 3: Reading from single_line.txt\n");
    line = get_next_line(fd);
    printf("%s", line);
    free(line);
    close(fd);

    // Test 4: Large lines
    fd = open("large_line.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening file!\n");
        return (1);
    }
    printf("\nTest 4: Reading from large_line.txt\n");
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);

    // Test 5: Multiple files
    int fd1 = open("file1.txt", O_RDONLY);
    int fd2 = open("file2.txt", O_RDONLY);
    if (fd1 == -1 || fd2 == -1)
    {
        printf("Error opening files!\n");
        return (1);
    }
    printf("\nTest 5: Reading from multiple files\n");
    line = get_next_line(fd1);
    printf("File 1: %s", line);
    free(line);
    line = get_next_line(fd2);
    printf("File 2: %s", line);
    free(line);
    close(fd1);
    close(fd2);

    // Test 6: Invalid file descriptor
    printf("\nTest 6: Invalid file descriptor\n");
    line = get_next_line(-1);
    if (line == NULL)
        printf("Invalid file descriptor handled correctly.\n");
    else
        printf("Error: Expected NULL, got %s\n", line);

    return (0);
}