#include "TermVision.h"
#include <string.h>
#include <unistd.h>

#define CLEAR "\033[H"
#define CLEAR_LENGTH 4

void	render(t_window window)
{
	if (!window->needs_render)
		return ;
	write(STDOUT_FILENO, CLEAR, CLEAR_LENGTH);
	for (size_t i = 0; i < window->h; i++)
	{
		if (!window->table[i])
		{
			write(STDERR_FILENO, "Null line", 9);
			continue ;
		}
		write(STDOUT_FILENO, window->table[i], strlen(window->table[i]));
	}
	window->needs_render = false;
}
