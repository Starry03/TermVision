#include "TermVision.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

t_colored_char	ColoredChar_Init(t_uchar c, t_color fg, t_color bg)
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

void	ColoredChar_Free(t_colored_char colored_char)
{
	if (!colored_char)
		return ;
	free(colored_char);
}

inline void	ColoredChar_SetChar(t_colored_char c, t_uchar new_c)
{
	if (!c)
		return ;
	c->c = new_c;
}

inline void	ColoredChar_SetBg(t_colored_char c, t_color bg)
{
	if (!c)
		return ;
	c->bg = bg;
}

inline void	ColoredChar_SetFg(t_colored_char c, t_color fg)
{
	if (!c)
		return ;
	c->fg = fg;
}
