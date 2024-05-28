#include "TermVision.h"

void	fill_window(t_window window, char c)
{
	size_t	i;
	size_t	j;

	if (!window)
		return ;
	i = 0;
	while (i < window->h)
	{
		j = 0;
		while (j < window->w - 1)
		{
			window->buf[i][j] = c;
			j++;
		}
		i++;
	}
	set_render(window, true);
}

void	force_newlines(t_window window)
{
	size_t i;

	if (!window)
		return ;
	i = 0;
	while (i < window->h)
	{
		window->buf[i][window->w - 2] = '\n';
		i++;
	}
	set_render(window, true);
}