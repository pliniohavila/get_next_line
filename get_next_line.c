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
        if (line != NULL)
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
    char        *nl;
    int         size;
    int         length;
    int         bytes_reads;
    static char state[BUFFER_SIZE];  // from React
    static int  k = 0;

    size = BUFFER_SIZE;
    line = (char*)malloc(sizeof(char) * size);
    if (!line) return NULL;
    ft_bzero(line, size);
    length = 0;
    if (k == 0)
        ft_bzero(state, size);
    if (k == 1)
    {
        if (ft_strchr(state, '\n') != NULL)
        {
            nl = ft_strchr(state, '\n') + 1;
            ft_strlcat(line, state, (int)(nl - state - 1));
            ft_strlcpy(buf, nl, BUFFER_SIZE - (int)(nl - state - 1));
            ft_strlcpy(state, buf, ft_strlen(buf));
            k = 1;
            return (line);
        }
        length = (int)ft_strlen(state);
    }
    ft_strlcpy(line, state, length);
    ft_bzero(buf, size);
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
            nl = ft_strchr(buf, '\n') + 1;
            ft_strlcat(line, buf, (int)(nl - buf - 1));
            ft_strlcpy(state, nl, BUFFER_SIZE - (int)(nl - buf - 1));
            k = 1;
            return (line);
        }
        ft_strlcat(line, buf, bytes_reads);
    }
    if (bytes_reads <= 0)
    {
        free(line);
        return NULL;
    }
    return (line); 
}