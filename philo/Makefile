NAME = philo

LIBNAME = libphilo.a

SRC = main.c \
\
		./function/function_util.c \
\
		./error/check_argument.c \
\
		./philo_function/philosophers_zero.c \
		./philo_function/philosophers_one.c \
		./philo_function/philosophers_two.c \
		./philo_function/philosophers_three.c \
		./philo_function/all_print.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g

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
	clear

test : re
	clear
	./$(NAME) 5 6 9 8 7

val : re
	clear
	valgrind -s --tool=helgrind ./$(NAME) 5 6 9 8 7

.PHONY : all clean fclean re


#--leak-check=full 