/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouanna <ajouanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:06:48 by ajouanna          #+#    #+#             */
/*   Updated: 2016/12/12 17:17:55 by ajouanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include <math.h>

# define DEFAULT_COLOR 0x00FF11FF
# define DEFAULT_WIDTH  1300
# define DEFAULT_HEIGHT 600
# define DEFAULT_RATIO 5
# define MA_PHOTO "./tonio.xpm"
# define IMG_X 60
# define IMG_Y 70
# ifndef M_PI
# define M_PI 3.14159
# endif 
# define END_LINE -0xFFFF
typedef		enum
{
	PARALLEL,
	ISOMETRIC,
	CONICAL,
	DUMMY
}		e_projection_type;

/*
** cette structure stocke l'environnement complet necessaire aux
** traitements
*/

typedef	struct			s_point
{
	double	x;
	double	y;
	int	color;
} 				t_point;

typedef struct	s_context
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_data;
	int		img_bpp;
	int		img_size_line;
	int		img_endian;
	int			**map;
	int		img_x;
	int		img_y;
	int		map_color;
	e_projection_type	proj_type;
	int		width;
	int		height;
	double		ratio_xy;
	double		ratio_z;
	int		is_monochrome;
	t_point		img_upper;
	t_point		img_lower;
	t_point		img_leftest;
	t_point		img_rightest;
	double		alpha;
	double		omega;
	int		data_width;
	int		z_max;
}				t_context;

int				setup_mlx(t_context *context);
int				read_file(char *filename, t_context *context);
void			draw_square(t_context *c, int x, int y);
void			display_commands(t_context *context);
void			process_image(t_context *context);
void			reprocess_image(t_context *context);
void			img_pixel_put(t_context *context, int x, int y, int color);
void			img_draw_line(t_context *context, int x1, int y1, int x2, int y2, int color);
void			clear_image(t_context *context);
void			dummy_transform(t_context *c);
void			parallel_transform(t_context *c);
void			isometric_transform(t_context *c);
void			conical_transform(t_context *c);
#endif
