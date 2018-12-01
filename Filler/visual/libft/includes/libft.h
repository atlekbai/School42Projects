/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:02:19 by dvdovenk          #+#    #+#             */
/*   Updated: 2017/02/01 17:22:14 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include <time.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <sys/ioctl.h>
# include "ft_structs.h"

# define BOLD				 	"\e[1m"
# define BOLD_DEF			 "{#bold}"
# define DIM 					"\e[2m"
# define DIM_DEF			 "{#dim}"
# define UNDERLINED				"\e[4m"
# define UNDERLINED_DEF		 "{#under}"
# define BLINK 					"\e[5m"
# define BLINK_DEF			 "{#blink}"
# define INV 					"\e[7m"
# define INV_DEF			 "{#inv}"
# define HIDDEN					"\e[8m"
# define HIDDEN_DEF			 "{#hidden}"
# define BLACK               	"\033[22;30m"
# define BLACK_COLOR         "{#black}"
# define RED                	 "\033[22;31m"
# define RED_COLOR           "{#red}"
# define GREEN              	 "\033[22;32m"
# define GREEN_COLOR         "{#green}"
# define YELLOW             	 "\033[22;33m"
# define YELLOW_COLOR        "{#yellow}"
# define BLUE                	"\033[22;34m"
# define BLUE_COLOR          "{#blue}"
# define MAGENTA            	 "\033[22;35m"
# define MAGENTA_COLOR       "{#magenta}"
# define CYAN                	"\033[22;36m"
# define CYAN_COLOR          "{#cyan}"
# define GRAY               	 "\033[22;37m"
# define GRAY_COLOR          "{#gray}"
# define DARK_GRAY          	 "\033[01;30m"
# define DARK_GRAY_COLOR     "{#darkgray}"
# define LIGHT_RED         	   "\033[01;31m"
# define LIGHT_RED_COLOR     "{#lightred}"
# define LIGHT_GREEN      	   "\033[01;32m"
# define LIGHT_GREEN_COLOR   "{#lightgreen}"
# define LIGHT_YELLOW           "\033[01;33m"
# define LIGHT_YELLOW_COLOR  "{#lightyellow}"
# define LIGHT_BLUE             "\033[01;34m"
# define LIGHT_BLUE_COLOR    "{#lightblue}"
# define LIGHT_MAGENTA          "\033[01;35m"
# define LIGHT_MAGENTA_COLOR "{#lightmagenta}"
# define LIGHT_CYAN             "\033[01;36m"
# define LIGHT_CYAN_COLOR    "{#lightcyan}"
# define WHITE                  "\033[01;37m"
# define WHITE_COLOR         "{#white}"
# define EOC         	        "\e[0m"
# define EOC_COLOR           "{#eoc}"
# define BLACK_BG       	     "\e[48;5;0m"
# define BLACK_BACK	         "{#black_bg}"
# define RED_BG                	 "\e[48;5;1m"
# define RED_BACK            "{#red_bg}"
# define GREEN_BG             	 "\e[48;5;2m"
# define GREEN_BACK          "{#green_bg}"
# define YELLOW_BG	   	 		"\e[48;5;3m"
# define YELLOW_BACK         "{#yellow_bg}"
# define BLUE_BG       	         "\e[48;5;4m"
# define BLUE_BACK           "{#blue_bg}"
# define MAGENTA_BG       	     "\e[48;5;5m"
# define MAGENTA_BACK        "{#magenta_bg}"
# define CYAN_BG              	 "\e[48;5;6m"
# define CYAN_BACK           "{#cyan_bg}"
# define GRAY_BG               	 "\e[48;5;7m"
# define GRAY_BACK           "{#gray_bg}"
# define DARK_GRAY_BG          	 "\e[48;5;8m"
# define DARK_GRAY_BACK      "{#darkgray_bg}"
# define LIGHT_RED_BG        	  "\e[48;5;9m"
# define LIGHT_RED_BACK      "{#lightred_bg}"
# define LIGHT_GREEN_BG        	 "\e[48;5;10m"
# define LIGHT_GREEN_BACK    "{#lightgreen_bg}"
# define LIGHT_YELLOW_BG         "\e[48;5;11m"
# define LIGHT_YELLOW_BACK   "{#lightyellow_bg}"
# define LIGHT_BLUE_BG           "\e[48;5;12m"
# define LIGHT_BLUE_BACK     "{#lightblue_bg}"
# define LIGHT_MAGENTA_BG        "\e[48;5;13m"
# define LIGHT_MAGENTA_BACK  "{#lightmagenta_bg}"
# define LIGHT_CYAN_BG           "\e[48;5;14m"
# define LIGHT_CYAN_BACK     "{#lightcyan_bg}"
# define WHITE_BG                "\e[48;5;15m"
# define WHITE_BACK          "{#white_bg}"
# define BIT7 127
# define BIT11 2047
# define BIT16 65535
# define BIT21 2097151
# define IFSAFE(x) if (!x) return (-1);
# define MALLOCSAFE(x) if (!x) return (0);
# define BUFF_SIZE 1

int		g_counter;
int		g_termwidth;

int		get_next_line(const int fd, char **line);
int		ft_atoi(char const *str);
void	ft_bzero(void *str, size_t l);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list	*ft_lstnew(void const *content, size_t content_size);
void	*ft_memalloc(size_t size);
void	*ft_memccpy(void *dst, void const *src, int c, size_t n);
void	*ft_memchr(void const *src, int c, size_t n);
int		ft_memcmp(void const *s1, void const *s2, size_t n);
void	*ft_memcpy(void *dst, void const *src, size_t n);
void	ft_memdel(void **ap);
void	*ft_memmove(void *dst, void const *src, size_t len);
void	*ft_memset(void *str, int ch, size_t len);
void	ft_putchar_fd(int c, int fd);
void	ft_putchar(int c);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putendl(char const *s);
void	ft_putnbr_fd(unsigned long long n, int fd);
void	ft_putnbr(unsigned long long n);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putstr(char const *s);
char	*ft_strcat(char *dest, char const *src);
char	*ft_strchr(char const *src, int c);
void	ft_strclr(char *s);
int		ft_strcmp(char const *s1, char const *s2);
char	*ft_strcpy(char *dest, char const *src);
void	ft_strdel(char **as);
char	*ft_strdup(char const *src);
int		ft_strequ(char const *s1, char const *s2);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dest, char const *src, size_t size);
size_t	ft_strlen(char const *str);
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strncat(char *dest, char const *src, int nb);
int		ft_strncmp(char const *s1, char const *s2, size_t n);
char	*ft_strncpy(char *dest, char const *src, size_t len);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strnew(size_t size);
char	*ft_strnstr(char const *big, char const *lit, size_t len);
char	*ft_strrchr(char const *src, int c);
char	**ft_strsplit(char const *s, char c);
char	*ft_strstr(char const *big, char const *little);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_strrev(char *str);
char	*ft_strlowcase(char *str);
char	*ft_strupcase(char *str);
int		*ft_sorttab(int *tabs, int size);
int		*ft_sortrevtab(int *tabs, int size);

/*
**	FT_FPRINTF
*/

void	ft_put_space_fd(t_desc *list, intmax_t num, int fd);
void	ft_wchar_null(char *data, t_desc *list, int fd);
void	ft_go_wstr(t_desc *list, wchar_t *data, int fd);
void	ft_strdel_array(char **data);
size_t	ft_len_num(uintmax_t value, int base);
void	ft_binary(t_desc *list, va_list arg, int fd);
int		ft_set_color(const char *data, int pos, int i);
char	*ft_zeroing_string(char *data, t_desc *list);
char	*ft_makestr_prec(char *str, t_desc *list);
void	ft_put_zero_fd(int size, int fd);
int		ft_take_wlen(uint32_t symbol);
int		ft_wstrlen(char **str);
void	ft_check_width(char *data, t_desc *list);
void	ft_n_check(va_list arg);
void	ft_putwstr_fd(char **s, int fd);
int		ft_check_content(char *data);
void	ft_strdel_16(char *data);
void	ft_check_star(char *data, t_desc *list, va_list arg, int tmp);
char	*ft_set_star(char *str, va_list arg);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_lower_case(char *str);
void	ft_flag_set_fd(char *d, t_desc *list, int fd);
char	*ft_place_hash(char *data, t_desc *list);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_last_flag(char *str);
char	*ft_takestring(const char *s, int p, t_desc *list);
char	*ft_parse_wchar(const uint32_t symbol, int p);
int		ft_printf_atoi(char const *str, int pos);
t_desc	*ft_create_new_list(void);
char	*ft_make_prec(char *str, t_desc *list);
int		ft_check_how_many(char *s, int p, char c);
void	ft_check_flag(char *str, t_desc *list);
void	ft_check_width(char *s, t_desc *list);
void	ft_check_prec(char *s, t_desc *list);
void	ft_check_length(char *str, t_desc *list);
void	ft_putchar_check(t_desc *list, va_list arg, int fd);
void	ft_putstr_check(t_desc *list, va_list arg, int fd);
void	ft_base_16(t_desc *list, va_list arg, int fd);
void	ft_base_8(t_desc *list, va_list arg, int fd);
void	ft_unsigned_check(t_desc *l, va_list arg, int fd);
void	ft_regular_num(t_desc *list, va_list arg, int fd);
char	*ft_itoa_base(uintmax_t value, t_desc *list, int b);
size_t	ft_numlen(intmax_t nb);
void	ft_place_shift_fd(int size, int fd);
char	*ft_place_zero(int size);
int		ft_output_len(const char *str, int pos);
void	ft_pointer_check(t_desc *list, va_list arg, int fd);
int		ft_fprintf(int fd, const char *format, ...);
int		ft_printf(const char *format, ...);

#endif
