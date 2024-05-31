#include "TermVision.h"
#include "colors.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define CLEAR "\e[3J\e[H\e[2J"
#define CLEAR2 "\e[1;1H\e[2J"
#define DISABLE_WRAPPING "\033[?7l"
#define ENABLE_WRAPPING "\033[?7h"
#define MOVE_CURSOR(x, y) printf("\x1b[%ld;%ldH", (y), (x))
#define HIDE_CURSOR() write(1, "\x1b[?25l", 6)
#define SHOW_CURSOR() write(1, "\x1b[?25h", 6)

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

static inline bool	c_changed(t_colored_char a, t_colored_char b)
{
	return (a->c != b->c || a->fg != b->fg || a->bg != b->bg);
}

/**
 * @brief renders the buffer to the window
 */
void	render(t_window window, size_t y_limit)
{
	t_colored_char	**buf;
	t_colored_char	**prev_buf;
	size_t			i;
	size_t			j;
	size_t			w;
	size_t			h;

	if (!window || !window->needs_render || !window->buf)
		return ;
	buf = window->buf;
	prev_buf = window->prev_buf;
	i = 0;
	w = window->w;
	h = (y_limit < window->h) ? y_limit : window->h;
	force_newlines(window);
	HIDE_CURSOR();
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			if (c_changed(buf[i][j], prev_buf[i][j]))
			{
				MOVE_CURSOR(j, i);
				if (buf[i][j]->c == '\n' && w - j != 1)
					printf("%s%s%c%s", buf[i][j]->fg, buf[i][j]->bg, ' ',
						RESET);
				else
					printf("%s%s%c%s", buf[i][j]->fg, buf[i][j]->bg,
						buf[i][j]->c, RESET);
			}
		}
	}
	SHOW_CURSOR();
	fflush(stdout);
	update_buffer(window);
	set_render(window, false);
}
