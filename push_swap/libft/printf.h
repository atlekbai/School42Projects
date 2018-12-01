/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:50:34 by hdanylev          #+#    #+#             */
/*   Updated: 2018/01/27 17:46:04 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <locale.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <fcntl.h>
# define BUFF_SIZE 1
# define ALL_FD 1024

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_all
{
	struct s_mod	*mod;
	struct s_capa	*capa;
	struct s_lat	*lat;
	va_list			conv;
	int				flag_stop;
	int				len;
	long			l;
	unsigned long	ul;
	unsigned int	*up;
	int				width;
	char			*output;
	int				x;
	char			spc;
	int				printed;
	int				ret;
	int				outlen;
	int				lennumonly;
	int				prec;
	int				flag_was;
}					t_all;

typedef struct		s_lat
{
	t_all			*(*f)(t_all*);
	int				flag;
	char			lat;
	int				num;
}					t_lat;

typedef struct		s_mod
{
	t_all			*(*f)(t_all*);
	char			mod;
	int				flag;
}					t_mod;

typedef struct		s_capa
{
	int				(*f)(t_all*);
	int				flag;
	char			spc;
}					t_capa;

int					ft_x(t_all *all);
int					ft_u(t_all *all);
int					ft_o(t_all *all);
int					ft_c(t_all *all);
int					ft_id(t_all *all);
int					ft_atoi(const char *str);
int					ft_atoi_base(char *str, int base);
int					ft_s(t_all *all);
int					ft_p(t_all *all);
int					ft_printf(const char *fmt, ...);
void				nbr_hex(long n);
void				ft_putstr(char const *str);
void				ft_putchar(char c);
char				ft_zero(t_all *all);
char				*ft_strnew(size_t size);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_itoa(long nb);
char				*ft_itoa_base(unsigned long value, int base);
char				*ft_itoa_base_l(long n, int base);
char				*ft_toupper(char *str);
size_t				ft_strlen(const char *str);
t_all				*ft_hash(t_all *all);
t_all				*ft_space(t_all *all);
t_all				*ft_count_output(t_all *all);
t_all				*ft_minus(t_all *all);
t_all				*ft_plus(t_all *all);
t_all				*ft_unicode(t_all *all);
t_all				*ft_check_mod2(t_all *all);
t_all				*ft_check_lat2(t_all *all);
t_all				*ft_field_width(t_all *all);
t_all				*ft_output(t_all *all);
t_all				*ft_precision(t_all *all);
t_all				*ft_l(t_all *all);
t_all				*ft_hh(t_all *all);
t_all				*ft_h(t_all *all);
t_all				*ft_j(t_all *all);
t_all				*ft_z(t_all *all);
t_all				*ft_persent(t_all *all);
t_all				*ft_zero_flag(t_all *all);
t_all				*ft_str_unicode(t_all *all, unsigned int u);
t_all				*write_flags(t_all *all);
t_all				*ft_check_capa(t_all *all, char x);
t_all				*ft_check_mod(t_all *all, char x);
t_all				*ft_check_lat(t_all *all, char *fmt);
t_all				*ft_read_lol(t_all *all, char *fmt);
t_all				*functions_pointers_capa(t_all *all);
t_all				*functions_pointers_mod(t_all *all);
t_all				*functions_pointers_flag(t_all *all);
t_all				*ft_null(t_all *all);
void				ft_lstdelone(t_list **alst, void(*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
t_list				*ft_lstnew(void const *content, size_t content_size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
void				ft_putendl_fd(char const *str, int fd);
void				ft_putnbr(int nb);
void				ft_putnbr_fd(int nb, int fd);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_strdel(char **str);
void				*ft_memcpy(void *dst, const void *src, size_t n);
int					get_next_line(const int fd, char **line);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *src, int c, size_t n);
void				ft_memdel(void **str);
void				ft_putstr(char const *str);
void				ft_putstr_fd(char const *str, int fd);
void				ft_bzero(void *b, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strncmp(char *s1, char *s2, size_t len);
char				*ft_strstr(const char *tmp, const char *srch);
char				*ft_strchr(const char *str, int c);
char				*ft_strdup(const char *str);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strrchr(const char *str, int c);
int					ft_strequ(const char *s1, const char *s2);
char				**ft_strsplit(const char *str, char c);
int					ft_strdigit(char *str);

#endif
