#include "TermVision.h"
#include <unistd.h>

#define CLEAR "\033[2J"
#define CLEAR_LENGTH 4

void	render(t_window window)
{
	if (!window->needs_render)
		return ;
	write(STDOUT_FILENO, CLEAR, CLEAR_LENGTH);
	for (size_t i = 0; i < window->h; i++)
	{
		write(STDOUT_FILENO, window->table[i], window->w);
		write(STDOUT_FILENO, "\n", 1);
	}
	window->needs_render = false;
}
