#include "TermVision.h"
#include "colors.h"
#include <stdlib.h>

t_window	new_window(size_t w, size_t h)
{
	t_window	window;

	window = (t_window)malloc(sizeof(s_window));
	if (!window)
		return (NULL);
	window->w = (w > 0 ? w : WINDOW_WIDTH);
	window->h = (h > 0 ? h : WINDOW_HEIGHT);
	window->buf = (t_colored_char **)malloc(sizeof(char *) * window->h);
	window->needs_render = true;
	if (!window->buf)
	{
		free(window);
		return (NULL);
	}
	for (size_t i = 0; i < window->h; i++)
		window->buf[i] = (t_colored_char *)malloc(window->w
				* sizeof(t_colored_char));
	for (size_t i = 0; i < window->h; i++)
		for (size_t j = 0; j < window->w; j++)
			window->buf[i][j] = new_colored_char(0, NULL, NULL);
	return (window);
}

void	del_window(t_window window)
{
	for (size_t i = 0; i < window->h; i++)
	{
		for (size_t j = 0; j < window->w; j++)
			del_colored_char(window->buf[i][j]);
		free(window->buf[i]);
	}
	free(window->buf);
	free(window);
}
