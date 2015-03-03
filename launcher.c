/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luperez <luperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 10:30:41 by luperez           #+#    #+#             */
/*   Updated: 2015/02/27 04:56:55 by luperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	you_are_here(void)
{
	char *path;

	path = NULL;
	if (!(path = getcwd(path, 0)))
		return ;
	ft_putstr("\033[1;32m[");
	ft_putstr(path);
	ft_putstr("]\033[0m");
	free(path);
}

void	exit_msg(int id)
{
	int	c;

	(void)id;
	if (env_s()->job)
		return ;
	ft_putstr("\nDo you really want to quit? [y/n]");
	c = getchar();
	if (c == 'y' || c == 'Y')
		exit(0);
	while (c != '\n' && c != EOF)
		c = getchar();
	if (c == EOF)
		ft_error("\nBye.");
	fflush(stdout);
	ft_putchar('\n');
	you_are_here();
}

void	sh1(void)
{
	t_env	*e;

	signal(SIGINT, exit_msg);
	e = env_s();
	if (!e)
		ft_error("Not authorized to create a env.");
	while (1)
	{
		you_are_here();
		read_cmd();
	}
}

void	launcher(char *cmd, char **arg)
{
	t_env	*e;
	char	**erzat;
	int		childs;
	pid_t	father;

	if (!cmd)
		return ;
	erzat = NULL;
	e = env_s();
	childs = -1;
	father = fork();
	e->job = 1;
	if (father > 0)
	{
		wait(&childs);
		e->job = 0;
		rm_erzat(erzat);
	}
	else
	{
		erzat = (e->env_i) ? NULL : lst_to_tab(e->var);
		e->env_i = 0;
		execve(cmd, arg, erzat);
	}
	(cmd) ? free(cmd) : (void)cmd;
}
