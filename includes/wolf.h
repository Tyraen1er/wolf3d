/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 08:21:53 by eferrand          #+#    #+#             */
/*   Updated: 2017/09/22 08:22:47 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include "libft.h"
# include "mlx.h"
# include <pthread.h>

# define WIDTH 1280
# define HEIGHT 720

typedef struct	s_img
{
	void		*addr;
	char		*img;
}				t_img;

/*
**	t_img[2] n est pas trasposable a d autres codes. Anti norminette qui
**	fait un warning contre (t_img[2]){};
*/

typedef struct	s_mlx
{
	void		*init;
	void		*win;
	t_img		img[2];
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

void			play(t_img game, t_img minimap, t_map data);
int				checkmap(char *map);
int				nb_lines(char *map);
int				nb_nb_line(char *map);
int				pars(char map);
t_map			loadfile(char *argv);
t_map			load_data(int nbl, int nb_elem, char *map, int i);

#endif
