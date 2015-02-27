/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luperez <luperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 10:30:57 by luperez           #+#    #+#             */
/*   Updated: 2015/01/25 10:30:58 by luperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char	**lst_to_tab(t_var *lst)
{
	size_t	len;
	t_var	*tmp;
	char	**tab;
	char	**start;

	len = 0;
	tmp = lst;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	if (len < 1 || !(tab = (char **)ft_memalloc(sizeof(char *) * len + 1)))
		return (NULL);
	lst = tmp;
	start = tab;
	while (lst)
	{
		*tab++ = ft_strtriconcat(lst->index, "=", lst->value);
		lst = lst->next;
	}
	return (start);
}

void	rm_erzat(char **tab)
{
	char	**start;

	if (!tab || !*tab)
		return ;
	start = tab;
	while (*tab)
		free(*tab++);
	free(start);
}