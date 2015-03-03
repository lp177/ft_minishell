/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luperez <luperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 10:30:41 by luperez           #+#    #+#             */
/*   Updated: 2015/01/25 10:30:43 by luperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	env(void)
{
	t_var	*var;

	var = env_s()->var;
	while (var)
	{
		if (var->index)
			ft_putstr(var->index);
		ft_putchar('=');
		if (var->value)
			ft_putendl(var->value);
		var = var->next;
	}
}

t_env	*new_env(void)
{
	t_env		*e;

	e = (t_env *)malloc(sizeof(t_env));
	if (!e)
		return (NULL);
	ft_bzero(e, sizeof(t_env));
	get_variables(e);
	return (e);
}

t_env	*env_s(void)
{
	static int		i = 0;
	static t_env	*e;

	if (i == 0 && ++i)
		e = new_env();
	return (e);
}

int		unsetenv(const char *index)
{
	t_var	**start;
	t_var	*var;

	start = &env_s()->var;
	if (!index || !(var = getvar(index)))
		return (-1);
	if (var == *start)
		*start = var->next;
	if (var->next)
		var->next->previous = var->previous;
	if (var->previous)
		var->previous->next = var->next;
	if (var->index)
		free(var->index);
	if (var->value)
		free(var->value);
	free(var);
	return (0);
}

int		setenv(const char *index, const char *value, int add)
{
	t_var	*tmp;
	t_var	*var;

	var = getvar(index);
	if (!var)
	{
		if (!(tmp = new_var(index, value, NULL)))
			return (-1);
		var_add(&(env_s()->var), tmp);
		return (1);
	}
	if (add == 1)
	{
		(var->value) ? free(var->value) : (void)var->value;
		var->value = ft_strdup((char *)value);
	}
	else
		ft_putendl("This key exist alreay, get parameter 3 at 1 for erase it.");
	return (0);
}
