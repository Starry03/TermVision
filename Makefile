KEYBOARD = -I./keyboard ./keyboard/keyboard.a
UniC = -I./UniC ./UniC/UniC.a

all:
	@cd ./UniC && make
	@cd ./keyboard && make
	@gcc *.c -o TermVision2 $(KEYBOARD)
	@echo "Compiled"

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all -s ./TermVision2

.PHONY: all keyboard
