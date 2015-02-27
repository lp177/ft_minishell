/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luperez <luperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 10:30:41 by luperez           #+#    #+#             */
/*   Updated: 2015/01/25 10:30:43 by luperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	debug_launcher(char *cmd, char **arg)
{
	ft_putstr("\n\033[1;34m---- Try to launch a commande ----\n");
	if (cmd && *cmd)
	{
		ft_putstr("  Cmd: ");
		ft_putendl(cmd);
	}
	else
		ft_putendl("    Empty commande");
	if (arg && *arg)
	{
		ft_putstr("\n  -- Argv: ");
		implode(arg, ", ");
	}
	else
		ft_putendl(" -- Empty arguments");
	ft_putstr("\n---- Commande launched ----\n\n\033[0m");
}

void	debug_octopus(char *cmd, char **path)
{
	ft_putstr("\n\033[0;36m---- Resolve path ----\n");
	if (cmd && *cmd)
	{
		ft_putstr("  Cmd: ");
		ft_putendl(cmd);
	}
	else
		ft_putendl("    Empty commande");
	if (path)
	{
		ft_putstr("\n  -- Path:\n    ");
		implode(path, "\n    ");
	}
	else
		ft_putendl("  -- Empty $PATH");
	ft_putstr("\n---- Path resolved ----\n\n\033[0m");
}

void	debug_get_path(char *path)
{
	char	**clean;

	ft_putstr("\n\033[1;32m---- Try to get path ----\n");
	if (path)
		ft_putendl(path);
	else
		ft_putendl("    $PATH not found");
	clean = clean_path(explode(&path[5], ":"));
	if (clean && *clean)
	{
		ft_putstr("\n -- Clean up:\n    ");
		implode(clean, "\n    ");
	}
	else
		ft_putendl(" -- Clean up return NULL");
	ft_putstr("\n---- Path geted ----\n\n\033[0m");
}

void	debug_setenv(t_var *var, int add)
{
	if (!var)
	{
		ft_putstr("Insert: index:");
		ft_putendl(env_s()->var->index);
		return ;
	}
	if (add)
	{
		ft_putstr("Maj: index =");
		ft_putendl(var->index);
	}
}

void	debug_unsetenv(const char *index)
{
	t_var	**start;
	t_var	*var;

	start = &env_s()->var;
	if (!index || !(var = getvar(index)))
	{
		ft_putstr("Index not found.");
		return ;
	}
	if (var == *start)
		ft_putendl("This variable is the first of the var list, switch needed");
	if (var->next)
		ft_putendl("Next cell founded I maj it.");
	else
		ft_putendl("No next cell.");
	if (var->previous)
		ft_putendl("Previous cell founded I maj it.");
	else
		ft_putendl("No previous cell.");
	if (!var->index)
		ft_putendl("No index founded.");
	if (!var->value)
		ft_putendl("No value founded.");
}
