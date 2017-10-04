/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:21:24 by eferrand          #+#    #+#             */
/*   Updated: 2017/10/01 04:50:22 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 100

# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

typedef struct					s_img
{
	void						*addr;
	char						*img;
}								t_img;

typedef struct					s_mlx
{
	void						*init;
	void						*win;
	t_img						image;
}								t_mlx;

typedef struct					s_fdline
{
	int							fd;
	int							p;
	int							pm;
	char						buf[BUFF_SIZE + 1];
	struct s_fdline				*next;
	struct s_fdline				*begin;
}								t_fdline;

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

int								ft_load_bitmap(int fd, t_bmp *bmp);
t_bmp							ft_uncompress_bitmap(t_bmp old);
int								*ft_read_bits(unsigned char *comp, int buf,
		int len);
int								ft_read_allstr(int fd, void **file);
int								get_next_line(const int fd, char**line);
void							ft_exit(int error);
int								ft_read_all(int fd, void **datafile);
void							*ft_memset(void *b, int c, size_t len);
void							ft_bzero(void *s, size_t n);
void							*ft_memcpy(void *dst, const void *src,
		size_t n);
void							*ft_memccpy(void *dst, const void *src,
		int c, size_t n);
void							*ft_memmove(void *dst, const void *src,
		size_t len);
void							*ft_memchr(const void *s, int c, size_t n);
void							*ft_realloc(void *str, int len_str,
		int add_bytes, int reading_speed);
int								ft_memcmp(const void *s1, const void *s2,
		size_t n);
size_t							ft_strlen(const char *s);
char							*ft_strdup(const char *s1);
char							*ft_strcpy(char *dst, const char *src);
char							*ft_strncpy(char *dst, const char *src,
		size_t len);
char							*ft_strcat(char *s1, const char *s2);
char							*ft_strncat(char *s1, const char *s2, size_t n);
size_t							ft_strlcat(char *dst, const char *src,
		size_t size);
char							*ft_strchr(const char *s, int c);
char							*ft_strrchr(const char *s, int c);
char							*ft_strstr(const char *big, const char *little);
char							*ft_strnstr(const char *big, const char *little,
		size_t len);
char							*ft_readfile(int fd);
int								ft_atoi_hex(char *nb);
int								ft_power(int a, int b);
int								ft_root(int a, int b);
int								ft_strcmp(const char *s1, const char *s2);
int								ft_strncmp(const char *s1, const char *s2,
		size_t n);
int								ft_atoi(const char *str);
int								ft_isalpha(int c);
int								ft_isdigit(int c);
int								ft_isalnum(int c);
int								ft_isascii(int c);
int								ft_isprint(int c);
int								ft_toupper(int c);
int								ft_tolower(int c);
void							*ft_memjoin(void *str1, int a, void *str2,
		int b);
void							*ft_memalloc(size_t size);
void							ft_memdel(void **ap);
char							*ft_strnew(size_t size);
void							ft_strdel(char **as);
void							ft_strclr(char *s);
void							ft_striter(char *a, void (*f)(char *b));
void							ft_striteri(char *a, void (*f)(unsigned int,
			char *b));
char							*ft_strmap(char const *a, char (*f)(char b));
char							*ft_strmapi(char const *a,
		char (*f)(unsigned int, char));
int								ft_strequ(char const *a, char const *b);
int								ft_strnequ(char const *a, char const *b,
		size_t c);
char							*ft_strsub(char const *a, unsigned int b,
		size_t c);
char							*ft_strjoin(char const *a, char const *b);
char							*ft_strtrim(char const *a);
char							**ft_strsplit(char const *a, char b);
char							*ft_itoa(int a);
void							ft_putchar(char a);
void							ft_putstr(char const *a);
void							ft_putendl(char const *a);
void							ft_putnbr(int a);
void							ft_putchar_fd(char a, int b);
void							ft_putstr_fd(char const *a, int b);
void							ft_putendl_fd(char const *a, int b);
void							ft_putnbr_fd(int a, int b);
t_list							*ft_lstnew(void const *a, size_t b);
void							ft_lstdelone(t_list **a,
		void (*del)(void*, size_t));
void							ft_lstdel(t_list **a,
		void (*del)(void*, size_t));
void							ft_lstadd(t_list **a, t_list *b);
void							ft_lstiter(t_list *lst,
		void (*f)(t_list *elem));
t_list							*ft_lstmap(t_list *a,
		t_list *(*f)(t_list *elem));
int								ft_isletter(char a);
t_point							ft_point_in_quad_to_ratio(t_quad a, t_point b);
t_point							ft_point_ratio_to_quad(t_point a, t_quad b);
t_quad							ft_create_quad(t_point a, t_point b);
t_point							ft_point_change_quad(t_point a, t_quad b,
		t_quad c);

#endif
