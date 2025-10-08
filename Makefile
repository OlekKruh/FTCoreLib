NAME = libft.a
AR = ar rcs
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
TEST_DIR = test

SRCS = $(wildcard *.c)
SRCS := $(filter-out test_main.c suite1.c suite2.c, $(SRCS))

OBJS = $(SRCS:.c=.o)

TEST_SRCS = $(addprefix $(TEST_DIR)/, test_main.c suite1.c suite2.c)
TEST_BIN = test_exec

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
		$(AR) $(NAME) $(OBJS)

all: $(NAME)

test: $(OBJS) $(TEST_SRCS)
	$(CC) $(CFLAGS) $(OBJS) $(TEST_SRCS) -I. -o $(TEST_BIN)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re help

help:
	@echo "help: displays commands"
	@echo "all: compile the library"
	@echo "clean: remove object files"
	@echo "fclean: remove object files and archive library"
	@echo "re: fclean and all"