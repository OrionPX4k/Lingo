##
## EPITECH PROJECT, 2023
## makefile
## File description:
## stumper
##

NAME =	lingo
TEST_NAME = unit_test

CC ?= gcc

RM = rm -f

SRC =	src/lingo.c \
		src/dictionary.c	\
		src/prompt.c	\
		src/word_find.c	\
		src/my_str_to_word_array.c
MAIN_SRC = src/main.c
TEST_SRC = tests/unit_test.c

OBJ = $(SRC:.c=.o)
MAIN_OBJ = $(MAIN_SRC:.c=.o)
TEST_OBJ = $(TEST_SRC:.c=.o)

CFLAGS = -Wall -Wextra
CPPFLAGS = -iquote ./include/

LDFLAG = -L
LDLIB = -lmy

TEST_FLAG = -lcriterion --coverage

all: $(OBJ) $(MAIN_OBJ)
	$(CC) -o $(NAME) $(OBJ) $(MAIN_OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) $(MAIN_OBJ)
	$(RM) $(TEST_OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(TEST_NAME)

re: fclean all

debug: $(CFLAGS) += -g3
debug: re

.PHONY: re fclean clean all debug

tests_run: $(CFLAGS) += -g3
tests_run: $(CFLAGS) += --coverage
tests_run: $(OBJ) $(TEST_OBJ)
	$(CC) -o $(TEST_NAME) $(OBJ) $(TEST_OBJ) $(CFLAGS) $(TEST_FLAG)
	./$(TEST_NAME)
