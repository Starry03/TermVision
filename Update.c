#include "TermVision.h"

void	change_bg(t_window window, t_color bg)
{
	size_t	i;
	size_t	j;

	if (!window)
		return ;
	i = 0;
	while (i < window->h)
	{
		j = 0;
		while (j < window->w)
		{
			window->buf[i][j]->bg = bg;
			j++;
		}
		i++;
	}
	ask_render(window);
}

void	change_color(t_window window, t_color fg)
{
	size_t	i;
	size_t	j;

	if (!window)
		return ;
	i = 0;
	while (i < window->h)
	{
		j = 0;
		while (j < window->w)
		{
			window->buf[i][j]->fg = fg;
			j++;
		}
		i++;
	}
	ask_render(window);
}

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
			window->buf[i][j]->c = c;
			j++;
		}
		i++;
	}
	ask_render(window);
}

void	force_newlines(t_window window)
{
	size_t	i;

	if (!window)
		return ;
	i = 0;
	while (i < window->h)
	{
		window->buf[i][window->w - 2]->c = '\n';
		i++;
	}
	ask_render(window);
}
