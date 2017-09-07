#ifndef WOLF_H
# define WOLF_H
# include "libft.h"

typedef struct	s_mlx
{
	void		*init;
	void		*win;
}				t_mlx;

char	**loadfile(char *argv);
int		pars(char *map);

#endif
