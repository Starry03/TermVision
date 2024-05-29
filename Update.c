#include "TermVision.h"
#include <stdio.h>

/**
 * @brief Change the background color of the window
 */
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
			set_bg(window->buf[i][j], bg);
			j++;
		}
		i++;
	}
	ask_render(window);
}

/**
 * @brief Change the foreground color of the window
 */
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
			set_fg(window->buf[i][j], fg);
			j++;
		}
		i++;
	}
	ask_render(window);
}

/**
 * @brief Fill the window with a character
 */
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
			set_c(window->buf[i][j], c);
			j++;
		}
		i++;
	}
	ask_render(window);
}

/**
 * @brief adds new line at the end of each line
 */
void	force_newlines(t_window window)
{
	size_t	i;

	if (!window)
		return ;
	i = 0;
	while (i < window->h)
	{
		set_c(window->buf[i][window->w - 1], '\n');
		i++;
	}
	ask_render(window);
}

void	set_line(t_window window, char *line, size_t x0, size_t y)
{
	size_t	i;

	if (!window || !line)
		return ;
	i = x0;
	while (line[i] && i < window->w)
	{
		set_c(window->buf[y][i], line[i]);
		i++;
	}
	ask_render(window);
}

static void	set_word(t_window window, void (*func)(t_colored_char, t_color),
		t_color color, size_t x0, size_t xf, size_t y)
{
	size_t	i;

	if (!window)
		return ;
	i = x0;
	while (i < xf)
	{
		func(window->buf[y][i], color);
		i++;
	}
	ask_render(window);
}

void	set_word_fg(t_window window, t_color fg, size_t x0, size_t xf,
		size_t y0)
{
	set_word(window, set_fg, fg, x0, xf, y0);
}

void	set_word_bg(t_window window, t_color bg, size_t x0, size_t xf,
		size_t y0)
{
	set_word(window, set_bg, bg, x0, xf, y0);
}
