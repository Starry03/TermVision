CC = gcc
FLAGS = -Wall -Wextra -Werror
CFILES = ColoredChar.c \
	Render.c \
	Update.c \
	Window.c
OFILES = $(CFILES:.c=.o)

NAME = termvision.a

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $@ $^
	ranlib $(NAME)

$(OFILES): %.o: %.c
	$(CC) -c -I. $(FLAGS) -o $@ $< 

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
