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

int		checkmap(char *map);
int		nb_lines(char *map);
int		nb_nb_line(char *map);
int		pars(char map);
t_map	loadfile(char *argv);
t_map	load_data(int nbl, int nb_elem, char *map, int i);

#endif
