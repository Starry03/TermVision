KEYBOARD = -I./keyboard/keyboard.h ../keyboard/keyboard.a -lpthread

all:
	gcc *.c -o TermVision2 $(KEYBOARD)