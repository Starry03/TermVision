#include "colors.h"
#include <stdlib.h>
#include <string.h>

static char	*colorvalue_to_string(uint16_t value)
{
	char	*buf;

	buf = (char *)calloc(4, sizeof(char));
	buf[2] = value % 10 + '0';
	buf[1] = (value / 10) % 10 + '0';
	buf[0] = (value / 100) % 10 + '0';
	return (buf);
}

static void	add_color(t_color color, uint16_t color_value)
{
	char	*buf;

	buf = colorvalue_to_string(color_value);
	strcat(color, buf);
	free(buf);
}

t_color	get_ansi_color(uint16_t red, uint16_t green, uint16_t blue, bool is_fg)
{
	t_color	color;

	if (red > 255 || green > 255 || blue > 255)
		return (NULL);
	color = (t_color)calloc(20, sizeof(char));
	color[20] = 0;
	strcpy(color, "\033[");
	if (is_fg)
		strcat(color, "38;2;");
	else
		strcat(color, "48;2;");
	add_color(color, red);
	strcat(color, ";");
	add_color(color, green);
	strcat(color, ";");
	add_color(color, blue);
	strcat(color, "m");
	return (color);
}
