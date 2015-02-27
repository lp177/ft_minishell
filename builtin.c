/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luperez <luperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 10:30:41 by luperez           #+#    #+#             */
/*   Updated: 2015/01/25 10:30:43 by luperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int		builtin(char *cmd, char **arg)
{
	if (!ft_strcmp(cmd, "env"))
	{
		env();
		return (1);
	}
	else if (!ft_strcmp(cmd, "setenv"))
	{
		if (!arg[0] || !arg[1] || !arg[2] || !arg[3])
			ft_putendl("Bad arguments.");
		else
			setenv(arg[1], arg[2], ft_atoi(arg[3]));
		return (1);
	}
	else if (!ft_strcmp(cmd, "unsetenv"))
	{
		if (!arg[0] || !arg[1])
			ft_putendl("bad arguments.");
		else
			unsetenv(arg[1]);
		return (1);
	}
	else if (!ft_strcmp(cmd, "cd"))
	{
		if (!arg[0] || !arg[1])
			cd(NULL);
		else
			cd(arg[1]);
		return (1);
	}
	return (0);
}