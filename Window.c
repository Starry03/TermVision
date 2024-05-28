#include "TermVision.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

t_window	new_window(size_t w, size_t h)
{
	t_window	window;

	window = (t_window)malloc(sizeof(s_window));
	if (!window)
		return (NULL);
	window->w = (w > 0 ? w : WINDOW_WIDTH);
	window->h = (h > 0 ? h : WINDOW_HEIGHT);
	window->buf = (char **)malloc(sizeof(char *) * window->h);
	window->needs_render = true;
	if (!window->buf)
	{
		free(window);
		return (NULL);
	}
	for (size_t i = 0; i < window->h; i++)
		window->buf[i] = (char *)calloc(window->w, sizeof(char));
	return (window);
}
void	del_window(t_window window)
{
	for (size_t i = 0; i < window->h; i++)
		free(window->buf[i]);
	free(window->buf);
	free(window);
}