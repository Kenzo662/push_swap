/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 02:11:11 by kenz              #+#    #+#             */
/*   Updated: 2024/03/06 21:33:54 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_utils
{
	int				len_a;
	int				len_b;
}					t_utils;

typedef struct s_lst
{
	int				nb;
	struct s_lst	*next;
}					t_lst;

typedef struct s_data
{
	t_lst			*lsta;
	t_lst			*lstb;
	t_utils			utils;
}					t_data;

t_lst				*push_front(t_lst *lst, int nb);
t_lst				*push_back(t_lst *lst, int nb);
t_lst				*pop_back(t_lst *lst);
t_lst				*pop_front(t_lst *lst);
t_lst				*clear_list(t_lst *lst);

void				sa(t_lst *lst);
void				sb(t_lst *lst);
void				ss(t_data *data);
void				pb(t_data *data);
void				pa(t_data *data);
void				ra(t_data *data);
void				rb(t_data *data);
void				rr(t_data *data);
void				rra(t_data *data, t_lst *lsta);
void				rrb(t_data *data, t_lst *lstb);
void				rrr(t_data *data, t_lst *lsta, t_lst *lstb);

int					already_sorted(t_data *data);
char				*cutline(char *str);
void				check_output(char *str, t_data *data);
void				check_av_char(char **tab, t_data *data);
void				check_argv(char **tab, t_data *data);
void				freetab(char **tab);
void				freelist(t_data *data);
int					ft_strcmp(char *s1, char *s2);
void				init_data(t_data *data);
void				init_lst_a(char **av, int ac, t_data *data);
char				**init_tab(char **av, int ac, t_data *data);
void				print_all_lst(t_lst *lsta, t_lst *lstb);
void				read_output(t_data *data);

#endif