#include "TermVision.h"
#include "colors.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define CLEAR "\e[3J\e[H\e[2J"
#define DISABLE_WRAPPING "\033[?7l"
#define ENABLE_WRAPPING "\033[?7h"

/**
 * @brief tries to set the render flag to true
 * @return true if the render flag was set to true, false otherwise
 */
bool	ask_render(t_window window)
{
	if (!window)
		return (false);
	set_render(window, true);
	return (window->needs_render);
}

/**
 * @brief set the render flag to a value
 */
void	set_render(t_window window, bool value)
{
	if (!window)
		return ;
	window->needs_render = value;
}

/**
 * @brief renders the buffer to the window
 */
void	render(t_window window, size_t y_limit)
{
	t_colored_char	**buf;
	t_colored_char	c_char;
	size_t			i;
	size_t			j;
	size_t			w;
	size_t			h;
	size_t			len_buf;
	char			*output;
	size_t			output_len;

	if (!window || !window->needs_render || !window->buf)
		return ;
	buf = window->buf;
	if (!buf)
		return ;
	i = 0;
	w = window->w;
	h = (y_limit < window->h) ? y_limit : window->h;
	output = calloc(8, sizeof(char));
	output_len = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			c_char = buf[i][j];
			output_len += snprintf(NULL, 0, "%s%s%c%s",
					(c_char->fg) ? c_char->fg : "",
					(c_char->bg) ? c_char->bg : "", (c_char->c) ? c_char->c : ' ', RESET);
			output = realloc(output, output_len + 1);
			len_buf = strlen(output);
			snprintf(output + len_buf, output_len + 1 - len_buf, "%s%s%c%s",
				c_char->fg, c_char->bg, c_char->c, RESET);
			j++;
		}
		i++;
	}
	write(STDOUT_FILENO, CLEAR, strlen(CLEAR));
	if (!output)
		return ;
	write(STDOUT_FILENO, output, output_len);
	free(output);
	set_render(window, false);
}
