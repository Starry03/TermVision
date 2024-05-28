#include "TermVision.h"
#include "keyboard/keyboard.h"
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int	main(int argc, char const *argv[])
{
	t_window	window;
	t_keyboard	*keyboard;
	char		k_buf;
	size_t		process_life;
	pid_t		pid;

	pid = getpid();
	process_life = 100;
	keyboard = keyboard_init('q', &k_buf);
	window = new_window(40, 35);
	if (!window)
		return (1);
	start_keylistener(keyboard);
	fill_window(window, 'b');
	force_newlines(window);
	render(window);
	keyboard_bruteforce_exit(keyboard);
	keyboard_free(keyboard);
	del_window(window);
	return (0);
}
