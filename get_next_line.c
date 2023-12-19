#include <stdio.h>
#include "get_next_line.h"


int     main(int argc, char **argv)
{
    int     fd;

    if (argc < 2)
        fd = STDIN_FILENO;
    else 
        fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        return (-1);
    // while (1)
    printf("%s\n", get_next_line(fd));
    if (fd > 2)
        close(fd);
    return (0);
}

int     get_line_len(int fd)
{
    int         bytes_reads;
    int         line_len;
    char        line[BUFFER_SIZE];

    ft_bzero(line, BUFFER_SIZE);
    line_len = 0;
    while ((bytes_reads = read(fd, line, BUFFER_SIZE - 1)) > 0)
    {
        if (ft_strchr(line, '\n'))
        {
            line_len += (int)(ft_strchr(line, '\n') - line);
            return (line_len);
        }
        line_len += bytes_reads;
    }
    return (line_len);
}

char    *get_next_line(int fd)
{
    char        *line;
    int         line_len;

    line = NULL;
    line_len = get_line_len(fd) + 1;
    printf("line_len: %d\n", line_len);
    line = (char*)malloc(sizeof(char) * line_len);
    if (read(fd, line, line_len) < 0)
        return NULL;
    line[line_len] = '\0';
    return (line); 
}

