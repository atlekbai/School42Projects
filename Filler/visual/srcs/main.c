/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 15:39:33 by dvdovenk          #+#    #+#             */
/*   Updated: 2018/04/24 22:05:44 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lib.h"

void		catch_signals(void);

static int	termcap_putchar(int c)
{
	write(2, &c, 1);
	return (0);
}

int			termcap_goto(char *cmd, int col, int row)
{
	char	*tmp;

	if ((tmp = tgetstr(cmd, NULL)) == NULL)
		return (1);
	tmp = tgoto(tmp, col, row);
	tputs(tmp, 0, termcap_putchar);
	return (0);
}

int			termcap_do(char *cmd)
{
	char	*tmp;

	if ((tmp = tgetstr(cmd, NULL)) == NULL)
		return (1);
	tputs(tmp, 0, termcap_putchar);
	return (0);
}

static void	getentry(char *tty)
{
	int		res;
	char	buf[1024];

	if ((res = tgetent(buf, tty)) < 1)
	{
		if (res < 0)
			ft_fprintf(2, "Error: Could not access the termcap data base.\n");
		else if (res == 0)
			ft_fprintf(2, "Error: Terminal type `%s' is not defined.\n",
				tty);
		exit(0);
	}
}

void		control_termios(void)
{
	char	*p;

	if (!(p = getenv("TERM")))
	{
		ft_fprintf(2, "Error: Specify a terminal type with ");
		ft_fprintf(2, "`setenv TERM <yourtype>`.\n");
		exit(1);
	}
	getentry(p);
	tcgetattr(STDERR_FILENO, &g_term_backup);
	tcgetattr(STDERR_FILENO, &g_term);
	g_term.c_lflag &= ~ECHO & ~ICANON;
	g_term.c_cc[VMIN] = 1;
	g_term.c_cc[VTIME] = 0;
	tcsetattr(STDERR_FILENO, TCSANOW, &g_term);
	termcap_do("os");
	termcap_do("vi");
	termcap_do("ti");
}

void		reset_termios(void)
{
	termcap_do("te");
	termcap_do("ve");
	tcsetattr(STDERR_FILENO, TCSANOW, &g_term_backup);
}

static void	pause_process(void)
{
	reset_termios();
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
}

static void	restore_process(void)
{
	control_termios();
	catch_signals();
}

int			exit_program(void)
{
	reset_termios();
	exit(0);
	return (0);
}

void		handler(int sig)
{
	if (sig == SIGTSTP)
		pause_process();
	else if (sig == SIGCONT)
		restore_process();
	else if (sig == SIGTERM || sig == SIGABRT || sig == SIGINT ||
		sig == SIGSTOP || sig == SIGKILL || sig == SIGQUIT)
		exit_program();
}

void		catch_signals(void)
{
	signal(SIGTERM, handler);
	signal(SIGABRT, handler);
	signal(SIGINT, handler);
	signal(SIGSTOP, handler);
	signal(SIGCONT, handler);
	signal(SIGTSTP, handler);
	signal(SIGKILL, handler);
	signal(SIGQUIT, handler);
}

void	print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		termcap_goto("cm", 0, i + 2);
		while (map[i][j])
		{
			if (map[i][j] == 'o')
				ft_printf("\033[0;106m \033[0m");
			else if (map[i][j] == 'O')
				ft_printf("\033[0;102m \033[0m");
			else if (map[i][j] == 'x')
				ft_printf("{#lightyellow_bg} \033[0m");
			else if (map[i][j] == 'X')
				ft_printf("\033[0;101m \033[0m");
			else
				ft_putchar(map[i][j]);
			j++;
		}
		i++;
	}
	termcap_goto("cm", 0, i + 2);
}

void	go_draw(void)
{
	char	*line;
	char	result[2][1024];
	char	**map;
	int		i;

	i = -1;
	map = (char**)ft_memalloc(sizeof(char*) * 101);
	i = -1;
	while (++i < 7 && (get_next_line(0, &line)))
		ft_strdel(&line);
	if (i < 7)
		exit_program();
	i = -1;
	while (get_next_line(0, &line))
	{
		if (ft_strncmp(line, "Plateau ", 8) == 0)
		{
			if (i > 0)
			{
				termcap_goto("cm", 0, 0);
				ft_printf("%s\n", line);
				get_next_line(0, &line);
				ft_printf("%s\n", line);
			}
			print_map(map);
			i = 0;
		}
		if (line[0] == '=')
		{
			sleep(1);
			ft_bzero(result[0], 1024);
			ft_memcpy(result[0], line, ft_strlen(line));
			get_next_line(0, &line);
			ft_bzero(result[1], 1024);
			ft_memcpy(result[1], line, ft_strlen(line));
			reset_termios();
			ft_printf("{#green}%s\n{#red}%s\n{#eoc}", result[0], result[1]);
			exit(0);
		}
		else if (ft_isdigit(line[0]) && !map[i])
		{
			map[i] = ft_strdup(line);
			i++;
		}
		else if (ft_isdigit(line[0]) && map[i])
		{
			ft_memcpy(map[i], line, ft_strlen(line));
			i++;
		}
		ft_strdel(&line);
	}
}

int				main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	control_termios();
	catch_signals();
	go_draw();
	reset_termios();
	return (0);
}
