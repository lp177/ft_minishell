/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luperez <luperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 10:30:41 by luperez           #+#    #+#             */
/*   Updated: 2015/01/25 10:30:43 by luperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	sh1(void)
{
	t_env	*e;

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
	char	**erzat;
	int		childs;
	pid_t	father;
	t_var	*vars;

	if (!cmd)
		return ;
	childs = -1;
	father = fork();
	if (father > 0)
		wait(&childs);
	else
	{	
		vars = env_s()->var;
		erzat = lst_to_tab(vars);
		execve(cmd, arg, erzat);
		rm_erzat(erzat);
	}
	free(cmd);
}
