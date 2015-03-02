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

void	exit_msg(int id)
{
	char	c;

	(void)id;
	if (env_s()->job)
		return ;
	ft_putstr("\nDo you really want to quit? [y/n]");
	c = getchar();
	if (c == 'y' || c == 'Y')
		exit(0);
	while (getchar() != '\n')
		;
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
	e->path = get_path();
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
	e = env_s();
	childs = -1;
	father = fork();
	e->job = 1;
	if (father > 0)
	{
		wait(&childs);
		e->job = 0;
	}
	else
	{
		erzat = (e->env_i) ? NULL : lst_to_tab(e->var);
		e->env_i = 0;
		execve(cmd, arg, erzat);
		if (erzat)
			rm_erzat(erzat);
	}
	free(cmd);
}
