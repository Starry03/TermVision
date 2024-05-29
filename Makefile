KEYBOARD = -I./keyboard ./keyboard/keyboard.a
UniC = -I./UniC ./UniC/UniC.a

all:
#	@cd ./UniC && make
	@cd ./keyboard && make
	gcc *.c -O3 -o TermVision2 $(KEYBOARD)
	@echo "Compiled"

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./TermVision2

.PHONY: all valgrind
