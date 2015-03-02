/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luperez <luperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 10:30:41 by luperez           #+#    #+#             */
/*   Updated: 2015/01/25 10:30:43 by luperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	load_default_env(t_env *e)
{
	char	*path;

	ft_putendl("Load default env...");
	if (!(path = getcwd(NULL, 0)))
		ft_error("You are definitely lost in the space,\
			we haven't path for your actual location.");
	e->var = new_var("PWD", path, NULL);
	new_var("PATH", "/bin", e->var);
	ft_putendl("Done.");
}

void	get_variables(t_env *e)
{
	int			i;
	t_var		*vars;
	char		*sep;
	char		*index;
	extern char	**environ;

	i = -1;
	vars = NULL;
	e->var = NULL;
	while (environ[++i])
	{
		if (!(sep = ft_strchr(environ[i], '=')) || !(sep + 1))
			ft_error("That variable is not a variable :/\n\
					Have realistic obliging to stop to smoke thx.");
		if (!(index = ft_strndup(environ[i], sep - environ[i]))
		|| !(vars = new_var(index, (sep + 1), vars)))
			return ;
		if (!e->var)
			e->var = vars;
		free(index);
	}
	if (!e->var)
		load_default_env(e);
}

void	var_add(t_var **vars, t_var *new_var)
{
	if (!new_var)
		return ;
	new_var->next = *vars;
	*vars = new_var;
}

t_var	*new_var(const char *index, const char *value, t_var *previous)
{
	t_var	*var;

	if (!index || !(var = (t_var *)ft_memalloc(sizeof(t_env))))
		return (NULL);
	var->index = ft_strdup(index);
	if (value)
		var->value = ft_strdup(value);
	if (previous)
	{
		var->previous = previous;
		previous->next = var;
	}
	return (var);
}

t_var	*getvar(const char *index)
{
	t_var	*scroll;

	if (!index)
		return (NULL);
	scroll = env_s()->var;
	while (scroll && ft_strcmp(scroll->index, index))
		scroll = scroll->next;
	return (scroll);
}
