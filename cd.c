/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luperez <luperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 10:30:57 by luperez           #+#    #+#             */
/*   Updated: 2015/01/25 10:30:58 by luperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	cd(char *path)
{
	char	*tmp;
	t_var	*home;

	tmp = NULL;
	if (!path || path[0] == '~')
		if ((home = getvar("HOME")))
		{
			if (!path)
				path = home->value;
			else
				path = ft_strconcat(home->value, &path[1]);
		}
	if (!path || (chdir(path) == -1 && (chdir(tmp = ft_strconcat(path, "/")))))
	{
		if (tmp)
			free(tmp);
		ft_putstrerrno("Please give me a valid path guy.\n");
		return ;
	}
	if (tmp)
		free(tmp);
	setenv("PWD", path, 1);
}
