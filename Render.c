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

static char	conv_char(t_uchar c, bool is_ui)
{
	if (is_ui || (c != '\n' && c))
		return (c);
	return (' ');
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
	size_t			output_len;
	char			*output;
	char			super_buf[32];

	if (!window || !window->needs_render || !window->buf)
		return ;
	buf = window->buf;
	i = 0;
	w = window->w;
	h = (y_limit < window->h) ? y_limit : window->h;
	force_newlines(window);
	output_len = 0;
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			c_char = buf[i][j];
			output_len += snprintf(NULL, 0, "%s%s%c%s", c_char->fg, c_char->bg,
					c_char->c, RESET);
		}
	}
	output = calloc(output_len + 1, sizeof(char));
	if (!output)
		return ;
	len_buf = 0;
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			c_char = buf[i][j];
			len_buf += snprintf(output + len_buf, output_len + 1 - len_buf,
					"%s%s%c%s", c_char->fg, c_char->bg, conv_char(c_char->c, w
						- j == 1), RESET);
		}
	}
	write(STDOUT_FILENO, CLEAR, strlen(CLEAR));
	write(STDOUT_FILENO, output, output_len);
	free(output);
	set_render(window, false);
}
