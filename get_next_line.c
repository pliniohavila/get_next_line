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
    static char state[BUFFER_SIZE];  // from React
    int         size;
    int         length;
    int         bytes_reads;

    size = BUFFER_SIZE;
    ft_bzero(state, size);
    line = (char*)malloc(sizeof(char) * size);
    if (!line) return NULL;
    length = (int)ft_strlen(state);
    ft_bzero(line, size);
    ft_strlcpy(line, state, length);
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
            ft_strlcat(line, buf, (int)(ft_strchr(buf, '\n') - buf));
            ft_strlcpy(state, ft_strchr(buf, '\n') + 1, BUFFER_SIZE);
            return (line);
        }
        ft_strlcat(line, buf, bytes_reads);
    }
    
    if (bytes_reads <= 0)
        return NULL;
    return (line); 
}
