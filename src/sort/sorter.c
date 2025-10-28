/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:05:34 by bpichyal          #+#    #+#             */
/*   Updated: 2025/10/28 15:04:48 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_chunks(t_stack *a, t_stack *b, int chunk_size)
{
	int	pushed;
	int	total;
	int	top;

	total = a->size;
	pushed = 0;
	while (pushed < total)
	{
		top = a->arr[0];
		if (top <= pushed)
		{
			do_pb(a, b);
			do_rb(b);
			pushed++;
		}
		else if (top <= pushed + chunk_size)
		{
			do_pb(a, b);
			pushed++;
		}
		else
			do_ra(a);
	}
}
