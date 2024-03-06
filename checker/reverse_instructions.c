/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 03:45:26 by kenz              #+#    #+#             */
/*   Updated: 2024/03/06 04:27:49 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_data *data)
{
	int	temp;

	temp = data->lsta->nb;
	data->lsta = pop_front(data->lsta);
	data->lsta = push_back(data->lsta, temp);
}

void	rb(t_data *data)
{
	int	temp;

	temp = data->lstb->nb;
	data->lstb = pop_front(data->lstb);
	data->lstb = push_back(data->lstb, temp);
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
}
