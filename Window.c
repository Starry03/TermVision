#include "TermVision.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

t_window	new_window(void)
{
	t_window	window;

	window = (t_window)malloc(sizeof(s_window));
	if (!window)
		return (NULL);
	window->w = WINDOW_WIDTH;
	window->h = WINDOW_HEIGHT;
	window->table = (char **)malloc(sizeof(char *) * WINDOW_HEIGHT);
	window->needs_render = true;
	if (!window->table)
	{
		free(window);
		return (NULL);
	}
	for (size_t i = 0; i < WINDOW_HEIGHT; i++)
	{
		window->table[i] = (char *)calloc(WINDOW_WIDTH, sizeof(char));
		memset(window->table[i], 'b', WINDOW_WIDTH - 1);
		window->table[i][WINDOW_WIDTH - 1] = '\n';
	}
	return (window);
}
void	del_window(t_window window)
{
	for (size_t i = 0; i < window->h; i++)
		free(window->table[i]);
	free(window->table);
	free(window);
}