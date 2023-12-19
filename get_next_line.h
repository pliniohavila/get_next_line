#ifndef GET_NEXT_LINE_H
 #define GET_NEXT_LINE_H
#endif 

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
 #define BUFFER_SIZE 32
#endif

char        *get_next_line(int fd);
int         get_line_len(int fd);
size_t      ft_strlen(const char *s);
void        ft_bzero(void *s, size_t n);
char        *ft_strchr(const char *s, size_t c);
