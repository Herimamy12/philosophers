NAME = philo

LIBNAME = libphilo.a

SRC = main.c \
\
		./function/function_util.c \
\
		./error/check_argument.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

PFLAGS = -pthread

CC = gcc

%.o : %.c
		$(CC) $(CFLAGS) $(PFLAGS) -o $@ -c $<

all : $(NAME)

$(NAME) : $(LIBNAME)
		$(CC) -o $@ $^

$(LIBNAME) : $(OBJ)
		ar rsc $@ $^

clean :
		rm -rf $(OBJ) $(LIBNAME)

fclean : clean
		rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re