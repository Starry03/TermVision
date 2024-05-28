#include "TermVision.h"

void	fill_window(t_window window, char c)
{
	size_t i;
	size_t j;

	if (!window)
		return ;
	i = 0;
	while (i < window->h)
	{
		j = 0;
		while (j < window->w)
		{
			window->table[i][j] = c;
			j++;
		}
		i++;
	}
	set_render(window, true);
}