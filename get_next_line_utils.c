#include "get_next_line.h"

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

size_t  ft_strlcpy(char *dst, const char *src, size_t n) 
{
    size_t      i;

    if ((!dst) && (!src))
        return (0);
    if (n == 0)
        return (ft_strlen(src));
    i = 0;
    while ((src[i] != '\0') && i < (n - 1))
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (ft_strlen(src));
}

size_t  ft_strlcat(char *dst, const char *src, size_t n)
{
    size_t      i;

    if ((!dst) && (!src))
        return (0);
    if (n == 0)
        return (ft_strlen(src));
    i = ft_strlen(dst);
    while ((*src != '\0') && (i < (n - 1)))
        dst[i++] = *src++;
    dst[i] = '\0';
    return (n + ft_strlen(src));
}