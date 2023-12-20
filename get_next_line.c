#include <stdio.h>
#include "get_next_line.h"


int     main(int argc, char **argv)
{
    int     fd;
    char    *line;

    if (argc < 2)
        fd = STDIN_FILENO;
    else 
        fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        return (-1);
    line = malloc(1 * sizeof(char));
    while (line != NULL)
    {
        free(line);
        line = get_next_line(fd);
        printf("%s\n", line);
    }
    if (fd > 2)
        close(fd);
    return (0);
}

char    *get_next_line(int fd)
{
    char        *line;
    char        *tmp_line;
    char        buf[BUFFER_SIZE];
    int         size;
    int         length;
    int         bytes_reads;

    size = BUFFER_SIZE;
    length = 0;
    line = (char*)malloc(sizeof(char) * size);
    if (!line) return NULL;
    ft_bzero(line, size);
    while ((bytes_reads = read(fd, buf, BUFFER_SIZE - 1)) > 0)
    {
        length += bytes_reads;
        if (length >= size)
        {
            size *= 2;
            tmp_line = (char*)malloc(sizeof(char) * size);
            if (!tmp_line) return NULL;
            ft_bzero(tmp_line, size);
            ft_strlcpy(tmp_line, line, length);
            free(line);
            line = tmp_line;
        }
        if (ft_strchr(buf, '\n') != NULL)
        {
            printf("(ft_strchr(buf, '\n')  %s\n", ft_strchr(buf, '\n'));
            ft_strlcat(line, buf, (int)(ft_strchr(buf, '\n') - buf));
            return (line);
        }
        ft_strlcat(line, buf, bytes_reads);
    }
    if (bytes_reads == -1)
        return NULL;
    return (line); 
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

