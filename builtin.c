/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luperez <luperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 10:30:41 by luperez           #+#    #+#             */
/*   Updated: 2015/01/25 10:30:43 by luperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	launch_env(char **arg)
{
	char	*cmd;

	if (arg[1])
	{
		if (!ft_strcmp(arg[1], "-i"))
		{
			if (!arg[2] || !ft_strcmp(arg[2], "cd")
				|| !ft_strcmp(arg[2], "setenv")
				|| !ft_strcmp(arg[2], "unsetenv"))
				return ;
			if (!(cmd = octopus(arg[2])))
				ft_putendl("Program not found");
			env_s()->env_i = 1;
			launcher(cmd, &arg[2]);
		}
		else
		{
			if (!(cmd = octopus(arg[1])))
				ft_putendl("Program not found");
			launcher(cmd, &arg[1]);
		}
	}
	else
		env();
}

void	launch_setenv(char **arg)
{
	char	*tmp;
	char	**cast;

	cast = NULL;
	if (!arg[0] || !arg[1] || (arg[2] && arg[3] && arg[4]))
	{
		ft_putendl("Bad arguments. (setenv index value overwrite)");
		return ;
	}
	if (!arg[2])
		cast = explode(arg[1], "=");
	if ((arg[2] && (ft_strchr(arg[1], '=') || ft_strchr(arg[2], '=')))
		|| ft_strchr(((tmp = ft_strchr(arg[1], '='))) ? tmp + 1 : NULL, '=')
		|| !ft_strchr(arg[1], '='))
	{
		ft_putendl("Invalid syntax. (setenv index value overwrite)");
		return ;
	}
	setenv((!arg[2] && cast) ? cast[0] : arg[1],
		(!arg[2] && cast[1]) ? cast[1] : arg[2],
		(!arg[3]) ? 0 : ft_atoi(arg[3]));
}

void	launch_unsetenv(char **arg)
{
	if (!arg[0] || !arg[1] || arg[2])
		ft_putendl("bad arguments. (unsetenv index)");
	else
		unsetenv(arg[1]);
}

void	launch_cd(char **arg)
{
	if (!arg[0] || !arg[1])
		cd(NULL);
	else
		cd(arg[1]);
}

int		builtin(char *cmd, char **arg)
{
	if (!ft_strcmp(cmd, "env"))
		launch_env(arg);
	else if (!ft_strcmp(cmd, "setenv"))
		launch_setenv(arg);
	else if (!ft_strcmp(cmd, "unsetenv"))
		launch_unsetenv(arg);
	else if (!ft_strcmp(cmd, "cd"))
		launch_cd(arg);
	else if (!ft_strcmp(cmd, "exit"))
		exit(0);
	else
		return (0);
	return (1);
}
