#include "TermVision.h"
#include "colors.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * @brief tries to set the Window_Render flag to true
 * @return true if the Window_Render flag was set to true, false otherwise
 */
bool	Window_AskRender(t_window window)
{
	if (!window)
		return (false);
	Window_SetRender(window, true);
	return (window->needs_render);
}

/**
 * @brief set the Window_Render flag to a value
 */
void	Window_SetRender(t_window window, bool value)
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
void	Window_Render(t_window window, size_t y_limit,
		bool leave_cursor_invisible)
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
				if (!buf[i][j]->c || (buf[i][j]->c == '\n' && w - j != 1))
					printf("%s%s%c%s", buf[i][j]->fg, buf[i][j]->bg, ' ',
						RESET);
				else
					printf("%s%s%c%s", buf[i][j]->fg, buf[i][j]->bg,
						buf[i][j]->c, RESET);
			}
		}
	}
	if (!leave_cursor_invisible)
		SHOW_CURSOR();
	fflush(stdout);
	Window_UpdateBuffer(window);
	Window_SetRender(window, false);
}
