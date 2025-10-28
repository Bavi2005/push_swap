/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 18:13:20 by bpichyal          #+#    #+#             */
/*   Updated: 2025/10/28 15:04:55 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_min_index(t_stack *a)
{
	int	i;
	int	min_index;

	if (a->size == 0)
		return (-1);
	min_index = 0;
	i = 1;
	while (i < a->size)
	{
		if (a->arr[i] < a->arr[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}

void	tiny_sort_five(t_stack *a, t_stack *b)
{
	int	idx;
	int	i;

	while (a->size > 3)
	{
		idx = find_min_index(a);
		if (idx <= a->size / 2)
		{
			i = 0;
			while (i++ < idx)
				do_ra(a);
		}
		else
		{
			i = 0;
			while (i++ < a->size - idx)
				do_rra(a);
		}
		do_pb(a, b);
	}
	tiny_sort(a);
	while (b->size > 0)
		do_pa(a, b);
}
