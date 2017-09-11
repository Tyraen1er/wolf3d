#ifndef WOLF_H
# define WOLF_H
# include "libft.h"

typedef struct	s_mlx
{
	void		*init;
	void		*win;
}				t_mlx;

typedef struct	s_coord
{
	float		x;
	float		y;
}				t_coord;

typedef struct	s_view
{
	t_coord		begin;
	t_coord		end;
}				t_view;

typedef struct	s_map
{
	float		**map;
	t_coord		player;
	t_view		view;
}				t_map;

float	**loadfile(char *argv);
int		pars(char map);

#endif
