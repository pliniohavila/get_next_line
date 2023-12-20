#include <stdio.h>
#include <stdlib.h>
// #include "get_next_line.h"

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

size_t  ft_strlcat(char *dst, const char *src, size_t n)
{
    size_t      i;
    size_t      k;
    size_t      len_src;
    
    len_src = ft_strlen(src);
    if ((!dst) && (!src))
        return (0);
    if (n == 0)
        return (ft_strlen(src));
    i = ft_strlen(dst);
    k = 0;
    while ((*src != '\0') && (k < n))
    {
        dst[i++] = *src++;
        k++;
    }
    dst[i] = '\0';
    return (n + len_src);
}


int main(void)
{
    char *s;

    s = (char*)malloc(sizeof(char) * 5);
    if (!s) return -1;
    ft_bzero(s, 5);
    printf("S: %s\n", s);
    printf("%d\n", (int)ft_strlen(s));
    ft_strlcat(s, "abc", 4);
    printf("S: %s\n", s);
    printf("%d\n", (int)ft_strlen(s));
    free(s);
    return (0);
}