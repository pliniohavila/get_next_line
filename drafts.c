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