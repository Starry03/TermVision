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
	window->table = (char **)malloc(sizeof(char *) * window->h);
	window->needs_render = true;
	if (!window->table)
	{
		free(window);
		return (NULL);
	}
	for (size_t i = 0; i < window->h; i++)
		window->table[i] = (char *)calloc(window->w, sizeof(char));
	return (window);
}
void	del_window(t_window window)
{
	for (size_t i = 0; i < window->h; i++)
		free(window->table[i]);
	free(window->table);
	free(window);
}