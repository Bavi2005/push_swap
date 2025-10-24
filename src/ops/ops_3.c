/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 15:48:55 by bpichyal          #+#    #+#             */
/*   Updated: 2025/10/24 17:07:18 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	do_ra(t_stack *a)
{
	int	tmp;
	int	i;

	if (a->size < 2)
		return ;
	tmp = a->arr[0];
	i = 0;
	while (i < a->size - 1)
	{
		a->arr[i] = a->arr[i + 1];
		i++;
	}
	a->arr[a->size - 1] = tmp;
	print_op("ra\n");
}

void	do_rb(t_stack *b)
{
	int	tmp;
	int	i;

	if (b->size < 2)
		return ;
	tmp = b->arr[0];
	i = 0;
	while (i < b->size - 1)
	{
		b->arr[i] = b->arr[i + 1];
		i++;
	}
	b->arr[b->size - 1] = tmp;
	print_op("rb\n");
}

void	do_rr(t_stack *a, t_stack *b)
{
	do_ra(a);
	do_rb(b);
	print_op("rr\n");
}
