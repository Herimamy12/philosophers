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
		./philo_function/philosophers_for.c \
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

test : all
	clear
	./$(NAME) 5 800 200 200

val : re
	clear
	valgrind -s  ./$(NAME) 5 800 200 200 3

.PHONY : all clean fclean re

hel: all
	clear
	valgrind --tool=helgrind -s ./philo 5 800 200 200 3
#--leak-check=full 