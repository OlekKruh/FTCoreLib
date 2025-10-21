NAME = libft.a
AR = ar rcs
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
TEST_DIR = test

SRCS = ft_atoi.c \
       ft_bzero.c \
       ft_calloc.c \
       ft_isalnum.c \
       ft_isalpha.c \
       ft_isascii.c \
       ft_isdigit.c \
       ft_isprint.c \
       ft_itoa.c \
       ft_memchr.c \
       ft_memcmp.c \
       ft_memcpy.c \
       ft_memmove.c \
       ft_memset.c \
       ft_putchar_fd.c \
       ft_putendl_fd.c \
       ft_putnbr_fd.c \
       ft_putstr_fd.c \
       ft_split.c \
       ft_strchr.c \
       ft_strdup.c \
       ft_striteri.c \
       ft_strjoin.c \
       ft_strlcat.c \
       ft_strlcpy.c \
       ft_strlen.c \
       ft_strmapi.c \
       ft_strncmp.c \
       ft_strnstr.c \
       ft_strrchr.c \
       ft_strtrim.c \
       ft_substr.c \
       ft_tolower.c \
       ft_toupper.c \

SRCS_B = ft_lstadd_back.c \
         ft_lstadd_front.c \
         ft_lstclear.c \
         ft_lstdelone.c \
         ft_lstiter.c \
         ft_lstlast.c \
         ft_lstnew.c \
         ft_lstsize.c \

SRCS := $(filter-out test_main.c suite1.c suite2.c, $(SRCS))

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

TEST_SRCS = $(addprefix $(TEST_DIR)/, test_main.c suite1.c suite2.c)
TEST_BIN = test_exec

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
		$(AR) $(NAME) $(OBJS)

all: $(NAME)

bonus: $(NAME) $(OBJS_B)
		$(AR) $(NAME) $(OBJS_B)

test: $(OBJS) $(TEST_SRCS)
	$(CC) $(CFLAGS) $(OBJS) $(TEST_SRCS) -lcunit -I. -o $(TEST_BIN)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(TEST_OBJS) $(OBJS_B) test_exec

re : fclean all

.PHONY: all clean fclean re help

help:
	@echo "help: displays commands"
	@echo "all: compile the library"
	@echo "test: compile test executable"
	@echo "clean: remove object files"
	@echo "fclean: remove object files and archive library"
	@echo "re: fclean and all"