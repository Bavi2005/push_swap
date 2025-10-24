/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 15:48:31 by bpichyal          #+#    #+#             */
/*   Updated: 2025/10/24 17:07:25 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	do_sa(t_stack *a)
{
	int	tmp;

	if (a->size < 2)
		return ;
	tmp = a->arr[0];
	a->arr[0] = a->arr[1];
	a->arr[1] = tmp;
	print_op("sa\n");
}

void	do_sb(t_stack *b)
{
	int	tmp;

	if (b->size < 2)
		return ;
	tmp = b->arr[0];
	b->arr[0] = b->arr[1];
	b->arr[1] = tmp;
	print_op("sb\n");
}

void	do_ss(t_stack *a, t_stack *b)
{
	do_sa(a);
	do_sb(b);
	print_op("ss\n");
}
