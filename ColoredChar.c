#include "TermVision.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

t_colored_char	new_colored_char(t_uchar c, t_color fg, t_color bg)
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

inline void	set_c(t_colored_char c, t_uchar new_c)
{
	c->c = new_c;
}

inline void	set_bg(t_colored_char c, t_color bg)
{
	c->bg = bg;
}

inline void	set_fg(t_colored_char c, t_color fg)
{
	c->fg = fg;
}
