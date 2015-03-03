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

void	rm_path(char **path)
{
	int	i;

	if (!path || !*path)
		return ;
	i = -1;
	while (path[++i])
		free(path[i]);
	free(path);
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
	if (cmd && (cmd[0] == '/' || cmd[0] == '.' || cmd[1] == '/') &&
		access(cmd, F_OK) != -1 && access(cmd, X_OK) != -1)
		return (ft_strdup(cmd));
	if (!(path = get_path()))
		ft_putstrerrno("Program not found.\n");
	cmd = ft_strconcat("/", cmd);
	while (path[++i] && access((tmp = ft_strconcat(path[i], cmd)), F_OK) == -1)
	{
		(tmp) ? free(tmp) : (void)tmp;
		tmp = NULL;
	}
	if (!path[i] || !tmp || access(tmp, X_OK) == -1)
	{
		(tmp) ? free(tmp) : (void)tmp;
		tmp = NULL;
		(!path[i] || !tmp) ? ft_putstrerrno("Program not found.\n") :
		ft_putstrerrno("No permissions for execute this program.\n");
	}
	(cmd) ? free(cmd) : (void)cmd;
	return (tmp);
}
