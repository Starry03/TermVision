#include "TermVision.h"
#include "colors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>

#define CLEAR "\e[3J\e[H\e[2J"
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
	t_colored_char	c_char;
	size_t			i;
	size_t			j;
	size_t			w;
	size_t			h;
	char			*output;
	size_t			output_len;

	if (!window || !window->needs_render || !window->buf)
		return ;
	buf = window->buf;
	if (!buf)
		return ;
	i = 0;
	w = window->w;
	h = window->h;
	output = calloc(sizeof(char), 8);
	output_len = 0;
	write(STDOUT_FILENO, CLEAR, strlen(CLEAR));
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			c_char = buf[i][j];
			output_len += snprintf(NULL, 0, "%s%s%c%s", c_char->fg, c_char->bg, c_char->c, RESET);
			output = realloc(output, output_len + 1);
			snprintf(output + strlen(output), output_len + 1 - strlen(output), "%s%s%c%s", c_char->fg, c_char->bg, c_char->c, RESET);
			j++;
		}
		i++;
	}
	printf("%s", output);
	free(output);
	fflush(stdout);
	set_render(window, false);
}
