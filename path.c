/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luperez <luperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 10:30:41 by luperez           #+#    #+#             */
/*   Updated: 2015/02/15 13:19:56 by luperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	you_are_here(void)
{
	char *path;

	path = NULL;
	path = getcwd(path, 0);
	ft_putstr("\033[1;32m[");
	ft_putstr(path);
	ft_putstr("]\033[0m");
	free(path);
}

char	**clean_path(char **path)
{
	int	y;
	int	x;

	if (!path)
		return (NULL);
	y = -1;
	while (path[++y])
	{
		x = -1;
		while (path[y][++x + 1])
			;
		while (x > 0 && path[y][x] == '/')
			path[y][x--] = '\0';
	}
	return (path);
}

char	**get_path(void)
{
	t_var	*path;

	if ((path = getvar("PATH")))
		return (clean_path(explode(path->value, ":")));
	return (NULL);
}

char	*octopus(char *cmd)
{
	int		i;
	char	*tmp;
	char	**path;
	i = -1;
	if (cmd && cmd[0] == '/' &&
		access(cmd, F_OK) != -1 && access(cmd, X_OK) != -1)
		return (ft_strdup(cmd));
	path = env_s()->path;
	cmd = ft_strconcat("/", cmd);
	while (path[++i] && access((tmp = ft_strconcat(path[i], cmd)), F_OK) == -1)
		if (tmp)
			free(tmp);
	if (path[i])
	{
		if (access(tmp, X_OK) == -1)
			ft_putstrerrno("No permissions for execute this program.\n");
		free(cmd);
		return (tmp);
	}
	else
		ft_putstrerrno("Program not found.\n");
	free(cmd);
	return (NULL);
}
