/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 08:21:53 by eferrand          #+#    #+#             */
/*   Updated: 2017/09/29 16:37:51 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include "libft.h"
# include "mlx.h"
# include <math.h>

# define NB_THREADS 16
# define WIDTH 1280
# define HEIGHT 720
# define WALL 600

typedef struct	s_map
{
	int 		limitx;
	int 		limity;
	double		**map;
	t_point		player;
	t_point		view;
}				t_map;

typedef struct	s_tmp
{
	int			pixelx;
	double		fov;
	double		camerax;
	double		rayposx;
	double		rayposy;
	double		raydirx;
	double		raydiry;
}				t_tmp;

typedef struct	s_all
{
	t_mlx		mlx;
	t_map		map;
	t_tmp		tmp;;
}				t_all;

void			display(t_all *data);
void			play(t_all data);
void			load_data(t_map *data, char *map);
int				checkmap(char *map);
int				nb_lines(char *map);
int				nb_nb_line(char *map);
int				pars(char map);
t_map			loadfile(char *argv);

#endif
