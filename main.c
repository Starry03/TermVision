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
	keyboard = keyboard_init('/', &k_buf);
	window = new_window(40, 35);
	if (!window)
		return (1);
	start_keylistener(keyboard);
	change_bg(window, BG_BLACK);
	change_color(window, CYAN);
	while (process_life--)
	{
		if (k_buf)
		{
			fill_window(window, k_buf);
			force_newlines(window);
			render(window);
			k_buf = 0;
		}
		usleep(100000);
	}
	keyboard_bruteforce_exit(keyboard);
	keyboard_free(keyboard);
	del_window(window);
	return (0);
}
