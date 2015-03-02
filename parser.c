/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luperez <luperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 10:30:41 by luperez           #+#    #+#             */
/*   Updated: 2015/01/25 10:30:43 by luperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int		scan_line(char *line)
{
	int	i;
	int	y;

	i = -1;
	y = -1;
	while (++i <= BUFF)
	{
		if (line[i] == 10)
		{
			if (i > 0 && line[i - 1] == '\\')
			{
				ft_putchar('>');
				line[y] = 10;
				line[y + 1] = '\0';
				i = BUFF + 1;
				y -= 2;
				continue ;
			}
			line[y + 1] = '\0';
			return (0);
		}
		if (++y != i)
			line[y] = line[i];
	}
	return (1);
}

char	*read_line(void)
{
	int		end;
	char	*tmp;
	char	*line;
	char	*buff;

	end = 1;
	tmp = NULL;
	line = NULL;
	if (!(buff = ft_strnew(BUFF)))
		ft_error_mem();
	while (end && read(0, buff, BUFF) > 0)
	{
		end = scan_line(buff);
		tmp = line;
		line = ft_strconcat(line, buff);
		if (tmp)
			free(tmp);
		tmp = line;
		line = ft_strtrim(line);
		if (tmp)
			free(tmp);
		ft_bzero(buff, (BUFF));
	}
	free(buff);
	return (line);
}

void	read_cmd(void)
{
	char	*buff;
	char	*cmd;
	char	**arg;

	buff = read_line();
	if (!buff || !*buff)
		return ;
	if (!(arg = explode(buff, " \t")))
		return ;
	cmd = arg[0];
	if (!builtin(cmd, arg) && (cmd = octopus(cmd)))
		launcher(cmd, arg);
	free(buff);
	while (*arg)
		free(*arg++);
}
