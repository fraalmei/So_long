/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:48:45 by fraalmei          #+#    #+#             */
/*   Updated: 2023/02/28 18:14:03 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

	// structure whith the elements of the window of the program
	// mlx_ptr	=> pointer to the iniciation of the program
	// win_ptr	=> pointer to the window
	// height	=> the altitude of the window
	// width	=> the amplitude of the window
typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}			t_win;

	// structure whith the elements of an image
	// win			=> window to which the image belongs
	// *img_ptr		=> pointer to the image
	// *addr		=> is the address of the bytes of the image (byte = 1 pixel)
	// h			=> height
	// w			=> width
	// bpp			=> bits per pixel
	// endian		=> format of the data
	// line_len		=> number of bytes one line holds (in the addrs)
typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

	//structure mwhith the elements of a square
	// x and y	=> represent the start of the square (top left corner)
	// size		=> height and width of the square
	// color	=> the color of the square
typedef struct s_square
{
	unsigned short int	x;
	unsigned short int	y;
	unsigned short int	size;
	int					color;
}						t_square;

void	pixel_put(t_img *img, int x, int y, int color);

int		gen_trgb(int opacity, int red, int green, int blue);

int		get_oppsite_color(int color);
int		get_opacity(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

#endif
