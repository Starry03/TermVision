KEYBOARD = -I./keyboard ./keyboard/keyboard.a

all:
	gcc *.c -o TermVision2 $(KEYBOARD)

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all -s ./TermVision2

.PHONY: all keyboard
