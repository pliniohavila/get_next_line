CC		= gcc
FLAGS	= -Wall -Wextra -Werror -g3


all: 	
	gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c -o main.out