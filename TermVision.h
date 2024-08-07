#ifndef TERMVISION_H
# define TERMVISION_H

# include "colors.h"
# include <stdbool.h>
# include <stddef.h>

# define WINDOW_WIDTH 96
# define WINDOW_HEIGHT 16

# define CLEAR "\e[3J\e[H\e[2J"
# define CLEAR2 "\e[1;1H\e[2J"
# define DISABLE_WRAPPING "\033[?7l"
# define ENABLE_WRAPPING "\033[?7h"
# define MOVE_CURSOR(x, y) printf("\x1b[%ld;%ldH", (y), (x))
# define HIDE_CURSOR() printf("\x1b[?25l")
# define SHOW_CURSOR() printf("\x1b[?25h")

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
t_colored_char			ColoredChar_Init(t_uchar c, t_color fg, t_color bg);
void					ColoredChar_Free(t_colored_char colored_char);
void					ColoredChar_SetBg(t_colored_char c, t_color bg);
void					ColoredChar_SetFg(t_colored_char c, t_color fg);
void					ColoredChar_SetChar(t_colored_char c, t_uchar new_c);
t_uchar					ColoredChar_GetChar(t_colored_char c);
t_color					ColoredChar_GetBg(t_colored_char c);
t_color					ColoredChar_GetFg(t_colored_char c);
void					ColoredChar_Reset(t_colored_char c);

// window
t_window				Window_Init(size_t w, size_t h);
void					Window_Free(t_window window);
void					Window_UpdateBuffer(t_window window);
t_colored_char			**Window_GetBuf(t_window window);

/* update */
void					change_color(t_window window, t_color fg);
void					change_bg(t_window window, t_color bg);
void					fill_window(t_window window, char c, size_t y0);
void					force_newlines(t_window window);

/* utils */
void					set_line(t_window window, char *line, size_t x0,
							size_t y);
void					set_word_fg(t_window window, t_color fg, size_t x0,
							size_t xf, size_t y0);
void					set_word_bg(t_window window, t_color bg, size_t x0,
							size_t xf, size_t y0);

/* Window_Render */
bool					Window_AskRender(t_window window);
void					Window_SetRender(t_window window, bool value);
void					Window_Render(t_window window, size_t y_limit,
							bool leave_cursor_invisible);

#endif