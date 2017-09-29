/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 08:21:53 by eferrand          #+#    #+#             */
/*   Updated: 2017/09/27 20:15:57 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_img
{
	void		*addr;
	char		*img;
}				t_img;

typedef struct	s_mlx
{
	void		*init;
	void		*win;
	t_img		img;
}				t_mlx;

typedef	struct					s_list
{
	void						*content;
	size_t						content_size;
	struct s_list				*next;
}								t_list;

typedef struct					s_btree
{
	struct s_btree				*left;
	struct s_btree				*right;
	void						*item;
}								t_btree;

typedef struct					s_point
{
	double						x;
	double						y;
}								t_point;

typedef struct					s_quad
{
	t_point						tl;
	t_point						br;
}								t_quad;

typedef struct					s_header_file_bmp
{
	short						bf_type;
	int							bf_size;
	int							reserved;
	int							bf_offset;
}								t_header_file_bmp;

typedef struct					s_info_bmp
{
	int							info_size;
	int							width;
	int							height;
	short						nb_planes;
	short						bits_per_pixel;
	int							compression;
	int							pic_size;
	int							h_pixel_per_meter;
	int							v_pixel_per_meter;
	int							nb_color_used;
	int							nb_color_important;
}								t_info_bmp;

typedef struct					s_bmp
{
	t_header_file_bmp			header;
	t_info_bmp					info;
	unsigned int				*palette;
	unsigned char				*picture;
}								t_bmp;

typedef struct	s_map
{
	int 						limitx;
	int 						limity;
	double						**map;
	t_point						player;
	t_point						view;
}								t_map;

typedef struct					s_tmp
{
	int							pixelx;
	double						fov;
}								t_tmp;

typedef struct					s_all
{
	t_mlx						mlx;
	t_map						map;
	t_tmp						tmp;;
}								t_all;

void							play(t_all *data);
void							load_data(t_map data, char *map);
int								checkmap(char *map);
int								nb_lines(char *map);
int								nb_nb_line(char *map);
int								pars(char map);
t_map							loadfile(char *argv);

#endif
