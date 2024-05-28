#include "TermVision.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define CLEAR "\x1b[2J"
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

static bool check_buf_integrity(t_window window)
{
	size_t line;

	line = 0;
	while (line < window->h)
	{
		if (window->buf[line][window->w - 1])
			return (false);
		line++;
	}
	return (true);
}

void	render(t_window window)
{
	if (!window || !window->needs_render)
		return ;
	if (!check_buf_integrity(window))
		return ;
	// write(STDOUT_FILENO, CLEAR, strlen(CLEAR));
	system("clear");
	for (size_t i = 0; i < window->h; i++)
		write(STDOUT_FILENO, window->buf[i], strlen(window->buf[i]));
	set_render(window, false);
}
