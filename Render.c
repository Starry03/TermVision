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
		write(STDOUT_FILENO, window->table[i], strlen(window->table[i]));
	window->needs_render = false;
}
