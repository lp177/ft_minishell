/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luperez <luperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 10:30:57 by luperez           #+#    #+#             */
/*   Updated: 2015/01/25 10:30:58 by luperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH1_H
# define SH1_H
# define BUFF 1024
# include <stdio.h>
# include <signal.h>
# include "libft/includes/libft.h"
# include "struct.h"

void	sh1(void);
void	env(void);
void	launcher(char *cmd, char **arg);

void	cd(char *path);
int		setenv(const char *index, const char *value, int add);
t_env	*new_env();
t_env	*env_s(void);

void	get_variables(t_env *e);
t_var	*getvar(const char *index);
void	var_add(t_var **vars, t_var *new_var);
t_var	*new_var(const char *index, const char *value, t_var *previous);

void	you_are_here(void);
char	**clean_path(char **path);
char	**get_path(void);
char	*octopus(char *cmd);

void	read_cmd(void);

int		builtin(char *cmd, char **arg);

int		scan_line(char *line);
char	*read_line(void);

char	**lst_to_tab(t_var *lst);
void	rm_erzat(char **tab);

void	debug_get_path(char *path);
void	debug_setenv(t_var *var, int add);
void	debug_unsetenv(const char *index);
void	debug_launcher(char *cmd, char **arg);
void	debug_octopus(char *cmd, char **path);

#endif
