/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 18:32:06 by dvdovenk          #+#    #+#             */
/*   Updated: 2017/05/02 18:32:07 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIB_H
# define FT_LIB_H

# include <sys/wait.h>
# include <signal.h>
# include <term.h>
# include <termios.h>
# include "ft_select_structs.h"
# include "../libft/includes/libft.h"

# define KEY_BACKSPACE		127
# define KEY_DEL			2117294875
# define KEY_LEFT 			4479771
# define KEY_RIGHT 			4414235
# define KEY_UP 			4283163
# define KEY_DOWN			4348699
# define KEY_ESC			27
# define KEY_SPACE			32
# define KEY_ENTER			10

struct termios	g_term;
struct termios	g_term_backup;

#endif
