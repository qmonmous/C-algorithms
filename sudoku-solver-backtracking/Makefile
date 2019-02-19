CC = gcc
FLAGS = -Wall -Werror -Wextra -o
FILES = sudoku_solver.c
NAME = solver

all : $(NAME)

$(NAME) :
	$(CC) $(FILES) $(FLAGS) $(NAME)

fclean :
	/bin/rm -f $(NAME)
re : fclean all

.PHONY : fclean re 