/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luperez <luperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 12:58:43 by luperez           #+#    #+#             */
/*   Updated: 2015/02/15 13:03:16 by luperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_var
{
	char			*index;
	char			*value;
	struct s_var	*previous;
	struct s_var	*next;
}				t_var;

typedef struct	s_env
{
	char		**table;
	char		**path;
	t_var		*var;
}				t_env;

#endif
