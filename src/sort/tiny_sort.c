/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 18:12:54 by bpichyal          #+#    #+#             */
/*   Updated: 2025/10/24 17:07:44 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	sort_three(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	x = a->arr[0];
	y = a->arr[1];
	z = a->arr[2];
	if (x > y && y < z && x < z)
		do_sa(a);
	else if (x > y && y > z)
	{
		do_sa(a);
		do_rra(a);
	}
	else if (x > y && y < z && x > z)
		do_ra(a);
	else if (x < y && y > z && x < z)
	{
		do_sa(a);
		do_ra(a);
	}
	else if (x < y && y > z && x > z)
		do_rra(a);
}

void	tiny_sort(t_stack *a)
{
	if (a->size == 2)
	{
		if (a->arr[0] > a->arr[1])
			do_sa(a);
	}
	else if (a->size == 3)
		sort_three(a);
}
