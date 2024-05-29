#ifndef COLORS_H
# define COLORS_H

// collection of ansii escape codes for colors

typedef char	*t_color;

# define RESET "\033[0m"

// foreground colors

# define BLACK "\033[38;2;0;0;0m"
# define RED "\033[38;2;255;0;0m"
# define GREEN "\033[38;2;0;255;0m"
# define YELLOW "\033[38;2;255;255;0m"
# define BLUE "\033[38;2;0;0;255m"
# define MAGENTA "\033[38;2;255;0;255m"
# define CYAN "\033[38;2;0;255;255m"
# define WHITE "\033[38;2;255;255;255m"

// background colors

# define BG_BLACK "\033[48;2;0;0;0m"
# define BG_RED "\033[48;2;255;0;0m"
# define BG_GREEN "\033[48;2;0;255;0m"
# define BG_YELLOW "\033[48;2;255;255;0m"
# define BG_BLUE "\033[48;2;0;0;255m"
# define BG_MAGENTA "\033[48;2;255;0;255m"
# define BG_CYAN "\033[48;2;0;255;255m"
# define BG_WHITE "\033[48;2;255;255;255m"

#endif