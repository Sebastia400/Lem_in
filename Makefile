##
## EPITECH PROJECT, 2021
## d10
## File description:
## description
##

OBJ = $(SRCS_C:.c=.o)

LIB = -L./lib/my -lmy

SFLAGS = -std=c99 -lncurses

SRC		=	sources/

SRC_C	=	main.c					\
			basicfunctions.c		\
			basic_functions_2.c		\
			basic_functions_3.c		\
			basic_functions_4.c		\
			str_word_array.c		\
			find_paths.c			\
			initialize_linked.c		\
			print_sentence.c 		\
			str_is_digit.c 			\
			find_char_array.c 		\
			create_linkeds.c		\
			save_information.c		\
			print_output.c			\
			save_information_2.c	\
			make_graph.c			\
			move_ants.c

SRCS_C	= 	$(addprefix $(SRC), $(SRC_C))

CFLAGS = -I./include -g

NAME = lem_in

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(SFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
	make clean
