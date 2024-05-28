#ifndef TERMVISION_H
# define TERMVISION_H

# include "colors.h"
# include <stdbool.h>
# include <stddef.h>

# define WINDOW_WIDTH 96
# define WINDOW_HEIGHT 16

typedef struct s_colored_char
{
	char				c;
	t_color				fg;
	t_color				bg;
}						t_colored_char_;

typedef t_colored_char_	*t_colored_char;

typedef struct s_window
{
	t_colored_char		**buf;
	size_t				w;
	size_t				h;
	bool				needs_render;
}						s_window;

typedef struct s_window	*t_window;

// colored char
t_colored_char			new_colored_char(char c, t_color fg, t_color bg);
void					del_colored_char(t_colored_char colored_char);

// window
t_window				new_window(size_t w, size_t h);
void					del_window(t_window window);

/* update */
void					change_color(t_window window, t_color fg);
void					change_bg(t_window window, t_color bg);
void					fill_window(t_window window, char c);
void					force_newlines(t_window window);

/* render */
bool					ask_render(t_window window);
void					set_render(t_window window, bool value);
void					render(t_window window);

#endif