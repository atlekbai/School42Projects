/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 19:23:44 by atlekbai          #+#    #+#             */
/*   Updated: 2018/03/25 16:52:54 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_stack
{
	char			*stack;
	int				fd;
	struct s_stack	*next;
}				t_stack;

# define ABS(x) ((x < 0) ? -(x) : (x))

int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strstr(const char *big, const char *little);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strncpy(char *dst, const char *src, size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlen(const char *s);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_strcat(char *s1, const char *s2);
void			*ft_memset(void *ptr, int value, size_t num);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memcpy(void *destination, const void *source, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memccpy(void *destination, const void *source,
							int c, size_t n);
int				ft_isprint(int c);
int				ft_isdigit(int c);
int				ft_isascii(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
void			ft_bzero(void *s, size_t n);
int				ft_atoi(const char *str);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(unsigned int c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(unsigned int c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int				ft_atoi_base(char const *str, int base);
void			ft_list_remove_if(t_list **begin_list,
									void *content, int (*cmp)());
int				ft_min(int *tab, int size);
int				ft_max(int *tab, int size);
t_list			*ft_lst_strsplit(char const *s, char c);
void			ft_lst_push_back(t_list **begin_list,
				void const *content, size_t content_size);
void			ft_lst_del_struct(void const *content, size_t content_size);
char			*ft_strndup(const char *s1, int n);
char			*ft_strnchr(const char *s, int c, int n);
t_stack			*ft_stacknew(char *content, int fd);
void			ft_stackdelone(t_stack **alst, void (*del)(char *, int));
void			ft_stackadd(t_stack **alst, t_stack *new);
int				get_next_line(const int fd, char **line);
char			*ft_itoa_base(int64_t n, int64_t base);
char			*ft_stradd(char *s1, char s2);
int				get_bytes(unsigned int c);
char			*ft_strjoin_free(char *s1, char *s2);

typedef struct	s_spec
{
	char	*flags;
	int		field_w;
	int		precision;
	int		prec;
	char	*mod;
	char	letter;
	int		pad;
}				t_spec;

int				ft_printf(char const *str, ...);
int				process(char *stack, va_list ap, char **str);
int				magic(t_spec spec, va_list ap, char **str);
int				is_end(char c);
int				is_spec(char c);
int				ft_isnotzero(int c);
char			*ft_dgtchr(const char *s);
char			*ft_mod(char *s);
int				ft_digit(t_spec spec, va_list ap, char **str);
int				ft_unsign(t_spec spec, va_list ap, char **str);
int				ft_octal(t_spec spec, va_list ap, char **str);
int				ft_hex(t_spec spec, va_list ap, char **str);
int				ft_char(t_spec spec, va_list ap);
int				ft_string(t_spec spec, va_list ap, char **str);
int				ft_percent(t_spec spec, char c, char **all);
char			*long_itoa_base(uintmax_t n, uintmax_t base, int c);
char			*giant_itoa_base(int64_t n, int64_t base);
size_t			wc_strlen(wchar_t *s);
wchar_t			*wc_strsub(wchar_t *s, unsigned int start, int len);
int				big_s_check(wchar_t *str);
void			wc_putstr(wchar_t *s);

void			ft_dgt_helper(t_spec *spec, int *len, int64_t d, char **str);
void			octal_helper(t_spec *spec, char **str, char **temp);
void			hex_helper(t_spec *spec, char **str, int *len, uintmax_t d);
void			color_bold(char const **str);
void			color_usual(char const **str);
void			color(char const **str, int size, char *color);

#endif
