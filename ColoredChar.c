#include "TermVision.h"
#include <stdlib.h>

t_colored_char	new_colored_char(char c, t_color fg, t_color bg)
{
	t_colored_char	colored_char;

	colored_char = (t_colored_char)malloc(sizeof(t_colored_char_));
	if (!colored_char)
		return (NULL);
	colored_char->c = c;
	colored_char->fg = fg;
	colored_char->bg = bg;
	return (colored_char);
}
void	del_colored_char(t_colored_char colored_char)
{
	free(colored_char);
}
