/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 17:21:51 by bpichyal          #+#    #+#             */
/*   Updated: 2025/10/24 17:07:29 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// ACTUAL DEFINITION — This was missing!
static void	perform_rotation(t_stack *s, char id, int direction)
{
	if (direction == 1)
	{
		if (id == 'a')
			do_ra(s);
		else
			do_rb(s);
	}
	else
	{
		if (id == 'a')
			do_rra(s);
		else
			do_rrb(s);
	}
}

static void	rotate_to_top(t_stack *s, int idx, char id)
{
	int	i;
	int	count;
	int	direction;

	if (!s || idx < 0)
		return ;
	count = idx;
	if (idx > s->size / 2)
		count = s->size - idx;
	direction = 0;
	if (idx <= s->size / 2)
		direction = 1;
	i = 0;
	while (i < count)
	{
		perform_rotation(s, id, direction);
		i++;
	}
}

static void	push_back_to_a(t_stack *a, t_stack *b)
{
	int	max;
	int	idx;

	while (b->size > 0)
	{
		max = stack_max(b);
		idx = stack_index(b, max);
		rotate_to_top(b, idx, 'b');
		do_pa(a, b);
	}
}

static void	sort_large(t_stack *a, t_stack *b)
{
	int	chunk_size;

	if (a->size <= 100)
		chunk_size = 15;
	else
		chunk_size = 30;
	push_chunks(a, b, chunk_size);
	push_back_to_a(a, b);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	if (!a || is_sorted(a))
		return ;
	if (a->size == 2 || a->size == 3)
		tiny_sort(a);
	else if (a->size <= 5)
		tiny_sort_five(a, b);
	else
		sort_large(a, b);
}
