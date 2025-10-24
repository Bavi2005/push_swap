/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 17:50:00 by bpichyal          #+#    #+#             */
/*   Updated: 2025/09/07 17:58:00 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	stack_max(t_stack *s)
{
	int	i;
	int	max;

	if (!s || s->size == 0)
		return (0);
	max = s->arr[0];
	i = 1;
	while (i < s->size)
	{
		if (s->arr[i] > max)
			max = s->arr[i];
		i++;
	}
	return (max);
}

int	stack_index(t_stack *s, int value)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (i < s->size)
	{
		if (s->arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}
