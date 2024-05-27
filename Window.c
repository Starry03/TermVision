#include "TermVision.h"
#include <string.h>
#include <stdlib.h>

t_window	new_window()
{
	t_window	window;

	window = malloc(sizeof(s_window));
	if (!window)
		return (NULL);
	window->w = WINDOW_WIDTH;
	window->h = WINDOW_HEIGHT;
	window->table = malloc(sizeof(char *) * WINDOW_HEIGHT);
	if (!window->table)
	{
		free(window);
		return (NULL);
	}
	for (size_t i = 0; i < WINDOW_HEIGHT; i++)
	{
		window->table[i] = malloc(sizeof(char) * WINDOW_WIDTH);
		memset(window->table[i], 0, WINDOW_WIDTH);
	}
}
void	del_window(t_window window)
{
	for (size_t i = 0; i < window->h; i++)
		free(window->table[i]);
	free(window->table);
	free(window);
}