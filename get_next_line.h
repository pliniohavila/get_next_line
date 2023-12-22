#ifndef GET_NEXT_LINE_H
 #define GET_NEXT_LINE_H
#endif 

#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
 #define BUFFER_SIZE 32
#endif

char        *get_next_line(int fd);
char        *extend_line(char *line, int length, int size);
int         get_size_buf(char *nl, char *buf);
size_t      ft_strlen(const char *s);
void        ft_bzero(void *s, size_t n);
char        *ft_strchr(const char *s, size_t c);
size_t      ft_strlcpy(char *dst, const char *src, size_t n);
size_t      ft_strlcat(char *dst, const char *src, size_t n);
