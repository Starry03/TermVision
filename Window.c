#include "TermVision.h"
#include "colors.h"
#include <assert.h>
#include <stdlib.h>

static t_colored_char	**allocate_buf(size_t w, size_t h)
{
	t_colored_char	**buf;

	buf = (t_colored_char **)malloc(sizeof(char *) * h);
	if (!buf)
		return (NULL);
	for (size_t i = 0; i < h; i++)
		buf[i] = (t_colored_char *)malloc(w * sizeof(t_colored_char));
	for (size_t i = 0; i < h; i++)
		for (size_t j = 0; j < w; j++)
			buf[i][j] = ColoredChar_Init(' ', NULL, NULL);
	return (buf);
}

/**
 * @brief Initializes a window
 * @param w The width of the window buffer
 * @param h The height of the window buffer
 * @return The window
 */
t_window	Window_Init(size_t w, size_t h)
{
	t_window	window;

	window = (t_window)malloc(sizeof(s_window));
	if (!window)
		return (NULL);
	window->w = (w > 0 ? w : WINDOW_WIDTH);
	window->h = (h > 0 ? h : WINDOW_HEIGHT);
	window->needs_render = true;
	window->buf = allocate_buf(window->w, window->h);
	window->prev_buf = allocate_buf(window->w, window->h);
	if (!window->buf || !window->prev_buf)
	{
		Window_Free(window);
		return (NULL);
	}
	return (window);
}

static void	dealloc_buf(t_colored_char **buf, size_t w, size_t h)
{
	for (size_t i = 0; i < h; i++)
	{
		for (size_t j = 0; j < w; j++)
			ColoredChar_Free(buf[i][j]);
		free(buf[i]);
	}
	free(buf);
}

void	Window_Free(t_window window)
{
	if (!window)
		return ;
	assert(window->buf);
	assert(window->prev_buf);
	if (window->buf)
		dealloc_buf(window->buf, window->w, window->h);
	if (window->prev_buf)
		dealloc_buf(window->prev_buf, window->w, window->h);
	free(window);
}

/**
 * @brief Updates the previous buffer with the current buffer
 * @note Don't use this function unless you know what you're doing
 */
void	Window_UpdateBuffer(t_window window)
{
	size_t			i;
	size_t			j;
	t_colored_char	**prev_buf;
	t_colored_char	**buf;

	prev_buf = window->prev_buf;
	buf = window->buf;
	i = 0;
	while (i < window->h)
	{
		j = 0;
		while (j < window->w)
		{
			prev_buf[i][j]->c = buf[i][j]->c;
			prev_buf[i][j]->fg = buf[i][j]->fg;
			prev_buf[i][j]->bg = buf[i][j]->bg;
			j++;
		}
		i++;
	}
}

/**
 * @return The buffer of the window
 */
t_colored_char	**Window_GetBuf(t_window window)
{
	if (!window)
		return (NULL);
	return (window->buf);
}
