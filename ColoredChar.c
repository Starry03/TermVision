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

void	ColoredChar_Reset(t_colored_char c)
{
	if (!c)
		return ;
	c->c = 0;
	c->fg = 0;
	c->bg = 0;
}

void	ColoredChar_SetChar(t_colored_char c, t_uchar new_c)
{
	if (!c)
		return ;
	c->c = new_c;
}

void	ColoredChar_SetBg(t_colored_char c, t_color bg)
{
	if (!c)
		return ;
	c->bg = bg;
}

void	ColoredChar_SetFg(t_colored_char c, t_color fg)
{
	if (!c)
		return ;
	c->fg = fg;
}

t_uchar	ColoredChar_GetChar(t_colored_char c)
{
	if (!c)
		return (0);
	return (c->c);
}

t_color	ColoredChar_GetBg(t_colored_char c)
{
	if (!c)
		return (0);
	return (c->bg);
}

t_color	ColoredChar_GetFg(t_colored_char c)
{
	if (!c)
		return (0);
	return (c->fg);
}
