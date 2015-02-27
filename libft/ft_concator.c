/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luperez <luperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/20 06:53:03 by luperez           #+#    #+#             */
/*   Updated: 2014/12/20 06:59:46 by luperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_concator(char *s1, char *s2)
{
	char	*s3;

	s3 = ft_strconcat(s1, s2);
	free(s1);
	free(s2);
	return (s3);
}