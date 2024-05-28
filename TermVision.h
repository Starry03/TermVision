#ifndef TERMVISION_H
# define TERMVISION_H

# include <stdbool.h>
# include <stddef.h>

# define WINDOW_WIDTH 96
# define WINDOW_HEIGHT 16

typedef struct s_window
{
	char				**buf;
	size_t				w;
	size_t				h;
	bool				needs_render;
}						s_window;

typedef struct s_window	*t_window;

t_window				new_window(size_t w, size_t h);
void					del_window(t_window window);

/* update */
void					fill_window(t_window window, char c);
void					force_newlines(t_window window);

/* render */
bool					ask_render(t_window window);
void					set_render(t_window window, bool value);
void					render(t_window window);

#endif