#include "../keyboard/keyboard.h"
#include "TermVision.h"
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int	main(int argc, char const *argv[])
{
	t_window	window;
	t_keyboard	*keyboard;
	char		k_buf;

	printf("pid: %d\n", getpid());
	window = new_window();
	if (!window)
		return (1);
	keyboard = keyboard_init('q');
	start_keylistener(keyboard, &k_buf);
	while (k_buf != 'q')
	{
		sleep(1);
		if (k_buf == 'r')
		{
			window->needs_render = true;
			render(window);
		}
	}
	del_window(window);
	return (0);
}
