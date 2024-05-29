#ifndef COLORS_H
# define COLORS_H

# include <stdbool.h>
# include <stdint.h>

// collection of ansii escape codes for colors

typedef char	*t_color;

# define RESET "\033[0m"

// foreground colors

# define BLACK "\033[38;2;0;0;0m"
# define RED "\033[38;2;178;34;34m" // Firebrick
# define GREEN "\033[38;2;34;139;34m" // Forest Green
# define YELLOW "\033[38;2;255;215;0m" // Gold
# define BLUE "\033[38;2;70;130;180m" // Steel Blue
# define MAGENTA "\033[38;2;199;21;133m" // Medium Violet Red
# define CYAN "\033[38;2;0;206;209m" // Dark Turquoise
# define WHITE "\033[38;2;245;245;245m" // White Smoke

// background colors

# define BG_BLACK "\033[48;2;0;0;0m"
# define BG_RED "\033[48;2;178;34;34m" // Firebrick
# define BG_GREEN "\033[48;2;34;139;34m" // Forest Green
# define BG_YELLOW "\033[48;2;255;215;0m" // Gold
# define BG_BLUE "\033[48;2;70;130;180m" // Steel Blue
# define BG_MAGENTA "\033[48;2;199;21;133m" // Medium Violet Red
# define BG_CYAN "\033[48;2;0;206;209m" // Dark Turquoise
# define BG_WHITE "\033[48;2;245;245;245m" // White Smoke

// text styles

# define BOLD "\033[1m"
# define UNDERLINE "\033[4m"
# define INVERT "\033[7m"

t_color			get_ansi_color(uint16_t red, uint16_t green, uint16_t blue,
					bool is_fg);

#endif