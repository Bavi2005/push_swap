/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                    +#+#+#+#+#+   +#+       */
/*   Created: 2025/10/24 18:00:00 by bpichyal         #+#    #+#             */
/*   Updated: 2025/10/24 18:00:00 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	silent_sa(t_stack *a)
{
	int	tmp;

	if (a->size < 2)
		return ;
	tmp = a->arr[0];
	a->arr[0] = a->arr[1];
	a->arr[1] = tmp;
}

static void	silent_pb(t_stack *a, t_stack *b)
{
	int	i;

	if (!a->size)
		return ;
	i = b->size++;
	while (--i >= 0)
		b->arr[i + 1] = b->arr[i];
	b->arr[0] = a->arr[0];
	i = -1;
	while (++i < --a->size)
		a->arr[i] = a->arr[i + 1];
}

static void	silent_ra(t_stack *a)
{
	int	tmp;
	int	i;

	if (a->size < 2)
		return ;
	tmp = a->arr[0];
	i = -1;
	while (++i < a->size - 1)
		a->arr[i] = a->arr[i + 1];
	a->arr[a->size - 1] = tmp;
}

void	exec_op(t_stack *a, t_stack *b, char *ln)
{
	if (!ft_strcmp(ln, "sa"))
		silent_sa(a);
	else if (!ft_strcmp(ln, "sb"))
		silent_sa(b);
	else if (!ft_strcmp(ln, "ss"))
	{
		silent_sa(a);
		silent_sa(b);
	}
	else if (!ft_strcmp(ln, "pa"))
		silent_pb(b, a);
	else if (!ft_strcmp(ln, "pb"))
		silent_pb(a, b);
	else if (!ft_strcmp(ln, "ra"))
		silent_ra(a);
	else if (!ft_strcmp(ln, "rb"))
		silent_ra(b);
	else if (!ft_strcmp(ln, "rr"))
	{
		silent_ra(a);
		silent_ra(b);
	}
	else if (!ft_strcmp(ln, "rra"))
		silent_rra(a);
	else if (!ft_strcmp(ln, "rrb"))
		silent_rra(b);
	else if (!ft_strcmp(ln, "rrr"))
	{
		silent_rra(a);
		silent_rra(b);
	}
	else
		exit_error();
}