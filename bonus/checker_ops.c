/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:59:43 by bpichyal          #+#    #+#             */
/*   Updated: 2025/10/28 15:10:41 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sa_silent(t_stack *a)
{
	int	tmp;

	if (!a || a->size < 2)
		return ;
	tmp = a->arr[0];
	a->arr[0] = a->arr[1];
	a->arr[1] = tmp;
}

static void	pb_silent(t_stack *a, t_stack *b)
{
	int	i;

	if (!a || !b || a->size == 0)
		return ;
	i = b->size;
	while (i > 0)
	{
		b->arr[i] = b->arr[i - 1];
		i--;
	}
	b->arr[0] = a->arr[0];
	b->size++;
	i = 0;
	while (i < a->size - 1)
	{
		a->arr[i] = a->arr[i + 1];
		i++;
	}
	a->size--;
}

static void	ra_silent(t_stack *a)
{
	int	tmp;
	int	i;

	if (!a || a->size < 2)
		return ;
	tmp = a->arr[0];
	i = 0;
	while (i < a->size - 1)
	{
		a->arr[i] = a->arr[i + 1];
		i++;
	}
	a->arr[a->size - 1] = tmp;
}

static int	exec_rotate_ops(t_stack *a, t_stack *b, char *line)
{
	if (!ft_strcmp(line, "ra"))
		ra_silent(a);
	else if (!ft_strcmp(line, "rb"))
		ra_silent(b);
	else if (!ft_strcmp(line, "rr"))
	{
		ra_silent(a);
		ra_silent(b);
	}
	else if (!ft_strcmp(line, "rra"))
		rra_silent(a);
	else if (!ft_strcmp(line, "rrb"))
		rra_silent(b);
	else if (!ft_strcmp(line, "rrr"))
	{
		rra_silent(a);
		rra_silent(b);
	}
	else
		return (0);
	return (1);
}

int	exec_op(t_stack *a, t_stack *b, char *line)
{
	if (!line || *line == '\0')
		return (1);
	if (!ft_strcmp(line, "sa"))
		sa_silent(a);
	else if (!ft_strcmp(line, "sb"))
		sa_silent(b);
	else if (!ft_strcmp(line, "ss"))
	{
		sa_silent(a);
		sa_silent(b);
	}
	else if (!ft_strcmp(line, "pa"))
		pb_silent(b, a);
	else if (!ft_strcmp(line, "pb"))
		pb_silent(a, b);
	else if (!exec_rotate_ops(a, b, line))
		return (0);
	return (1);
}
