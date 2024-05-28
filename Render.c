#include "TermVision.h"
#include "colors.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define CLEAR "\e[1;1H\e[2J"
#define DISABLE_WRAPPING "\033[?7l"
#define ENABLE_WRAPPING "\033[?7h"

bool	ask_render(t_window window)
{
	if (!window)
		return (false);
	set_render(window, true);
	return (window->needs_render);
}

void	set_render(t_window window, bool value)
{
	if (!window)
		return ;
	window->needs_render = value;
}

void	render(t_window window)
{
	t_colored_char	**buf;

	if (!window || !window->needs_render || !window->buf)
		return ;
	buf = window->buf;
	write(STDOUT_FILENO, CLEAR, strlen(CLEAR));
	for (size_t i = 0; i < window->h; i++)
	{
		for (size_t j = 0; j < window->w; j++)
		{
			if (buf[i][j]->bg)
				write(STDOUT_FILENO, buf[i][j]->bg, strlen(buf[i][j]->bg));
			if (buf[i][j]->fg)
			{
				write(STDOUT_FILENO, buf[i][j]->fg, strlen(buf[i][j]->fg));
				write(STDOUT_FILENO, &(buf[i][j]->c), 1);
				write(STDOUT_FILENO, RESET, strlen(RESET));
				continue ;
			}
			write(STDOUT_FILENO, &buf[i][j]->c, 1);
		}
	}
	set_render(window, false);
}
