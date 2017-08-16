/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 01:29:14 by eferrand          #+#    #+#             */
/*   Updated: 2017/03/22 10:29:43 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_fdline	*ft_create(const int fd)
{
	t_fdline	*new;

	new = NULL;
	if (!(new = malloc(sizeof(t_fdline))))
		return (NULL);
	new->fd = (int)fd;
	new->pm = -2;
	new->next = NULL;
	new->begin = NULL;
	return (new);
}

static t_fdline	*ft_which_fd(const int fd, int change)
{
	static t_fdline	*begin = NULL;
	t_fdline		*tmp;

	if (change)
	{
		begin = begin->next;
		return (begin);
	}
	if ((tmp = begin))
	{
		while (tmp->next && fd != tmp->fd)
			tmp = tmp->next;
		if (fd != tmp->fd)
		{
			tmp->next = ft_create(fd);
			tmp = tmp->next;
		}
	}
	if (!begin)
	{
		begin = ft_create(fd);
		tmp = begin;
	}
	tmp->begin = begin;
	return (tmp);
}

static	void	ft_freetheworld(t_fdline **vrf)
{
	t_fdline	*tmp;

	tmp = (*vrf)->begin;
	if (*vrf == tmp)
	{
		ft_which_fd(0, 1);
		while (tmp->next)
		{
			tmp = tmp->next;
			tmp->begin = (*vrf)->next;
		}
	}
	else
	{
		while (tmp->next && tmp->next != *vrf)
			tmp = tmp->next;
		tmp->next = (*vrf)->next;
	}
	ft_memdel((void **)vrf);
}

static int		ft_attrib(char **line, t_fdline *vrf)
{
	int		a;

	a = 0;
	while (a != -1)
	{
		while (vrf->buf[vrf->p] != '\n' && vrf->buf[vrf->p])
			line[0][a++] = vrf->buf[vrf->p++];
		line[0][a] = '\0';
		if (!vrf->buf[vrf->p] && vrf->pm && vrf->p)
		{
			if (-1 == (vrf->pm = read(vrf->fd, vrf->buf, BUFF_SIZE)))
				return (-1);
			vrf->buf[vrf->pm] = 0;
			*line = ft_realloc(*line, ft_strlen(*line) + 1, BUFF_SIZE, 1);
			vrf->p = 0;
		}
		if ((vrf->buf[vrf->p] == '\n' || !vrf->pm) && (a = -1))
		{
			line[0][ft_strlen(*line)] = '\0';
			if (++vrf->p >= vrf->pm)
				vrf->pm = -2;
		}
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	t_fdline		*vrf;

	if (fd < 0 || BUFF_SIZE < 0 || !line)
		return (-1);
	*line = (char *)malloc(BUFF_SIZE + 1);
	**line = 0;
	line[0][BUFF_SIZE] = 0;
	vrf = ft_which_fd(fd, 0);
	if (vrf->pm == -2)
	{
		if (-1 == (vrf->pm = read(vrf->fd, vrf->buf, BUFF_SIZE)))
		{
			*line = NULL;
			ft_freetheworld(&vrf);
			return (-1);
		}
		if (!vrf->pm && (vrf->pm = -2) == -2)
		{
			ft_freetheworld(&vrf);
			return (0);
		}
		vrf->p = 0;
		vrf->buf[vrf->pm] = 0;
	}
	return (ft_attrib(line, vrf));
}
