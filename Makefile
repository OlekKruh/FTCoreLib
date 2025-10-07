# определяем название статичиской библиотеки. концовка .a обазначает статичность
NAME = libft.a
# ar - архиватор, r - заменить или добавить файлы, c - создать архив, s - создать индекс для быстрой работы
AR = ar rcs
# компелятор gcc можна так же заменить на clang
CC = gcc
# команда на пренудительное удаление
RM = rm -f
# флаги для компиляции.
# -Wall - включаем предуприждения
# -Wextra - включаем доп предупреждения
# -Werror - переводим предупреждения в ошибки
CFLAGS = -Wall -Wextra -Werror
# делаем список файлов с разширением .c с исключением некоторых файлов нам не нужных
# в моем случае тестовый файл test_main.c исключен из списка
# танцы с бубно вокруг директории тест
SRCS = $(wildcard *.c)
SRCS := $(filter-out test_main.c suite1.c suite2.c, $(SRCS))

# при помощи этой переменной мы заменим разширение файлов с .c на .o
OBJS = $(SRCS:.c=.o)
# правело для преобразования файлов расширениями с .c на .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
# правило сборки библиотеки из объектных файлов
$(NAME): $(OBJS)
		$(AR) $(NAME) $(OBJS)
# основная цель
all: $(NAME)
# удаление обектных файлов
clean:
	$(RM) $(OBJS)
# удаление обектных файлов и библиотеки
fclean: clean
	$(RM) $(NAME)
# очистка и сборка заново
re : fclean all
# псевдоцель для команд, не связанных с файлами
.PHONY: all clean fclean re help
# это так просто балуюсь
help:
	@echo "help: displays commands"
	@echo "all: compile the library"
	@echo "clean: remove object files"
	@echo "fclean: remove object files and archive library"
	@echo "re: fclean and all"