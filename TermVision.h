#ifndef TERMVISION_H
# define TERMVISION_H

# include "colors.h"
# include <stdbool.h>
# include <stddef.h>

# define WINDOW_WIDTH 96
# define WINDOW_HEIGHT 16

typedef unsigned char	t_uchar;

typedef struct s_colored_char
{
	t_color				fg;
	t_color				bg;
	t_uchar				c;
}						t_colored_char_;

typedef t_colored_char_	*t_colored_char;

typedef struct s_window
{
	t_colored_char		**buf;
	t_colored_char		**prev_buf;
	size_t				w;
	size_t				h;
	bool				needs_render;
}						s_window;

typedef struct s_window	*t_window;

// colored char
t_colored_char			new_colored_char(t_uchar c, t_color fg, t_color bg);
void					del_colored_char(t_colored_char colored_char);
void					set_bg(t_colored_char c, t_color bg);
void					set_fg(t_colored_char c, t_color fg);
void					set_c(t_colored_char c, t_uchar new_c);

// window
t_window				new_window(size_t w, size_t h);
void					del_window(t_window window);
void					update_buffer(t_window window);

/* update */
void					change_color(t_window window, t_color fg);
void					change_bg(t_window window, t_color bg);
void					fill_window(t_window window, char c, size_t y0);
void					force_newlines(t_window window);
void					set_line(t_window window, char *line, size_t x0,
							size_t y);
void					set_word_fg(t_window window, t_color fg, size_t x0,
							size_t xf, size_t y0);
void					set_word_bg(t_window window, t_color bg, size_t x0,
							size_t xf, size_t y0);

/* render */
bool					ask_render(t_window window);
void					set_render(t_window window, bool value);
void					render(t_window window, size_t y_limit);

#endif