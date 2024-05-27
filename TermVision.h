#ifndef TERMVISION_H
# define TERMVISION_H

# include <stdbool.h>
# include <stddef.h>

# define WINDOW_WIDTH 40
# define WINDOW_HEIGHT 16

typedef struct s_window
{
	char				**table;
	size_t				w;
	size_t				h;
	bool				needs_render;
}						s_window;

typedef struct s_window	*t_window;

t_window				new_window(void);
void					del_window(t_window window);

/* update */
void					fill_window(t_window window, char c);

/* render */
void					render(t_window window);

#endif