#include "libft.h"

char    *ft_strchr(const char *s, size_t c)
{
    size_t      i;
    char        cmp;

    i = 0;
    cmp = (char)c;
    while (s[i] != '\0')
    {
        if (s[i] == cmp)
            return ((char*)&s[i]);
        i++;
    }
    return (NULL);
}

size_t      ft_strlen(const char *s)
{
    size_t      i;

    i = 0;
    while (*s++)
        i++;
    return(i);
}

void    ft_bzero(void *s, size_t n)
{
    size_t          i;
    unsigned char   *buf;

    i = 0;
    buf = (unsigned char*)s;
    while(i < n)
        buf[i++] = '\0';

    return;
}