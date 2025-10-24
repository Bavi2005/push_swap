/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 17:20:00 by bpichyal          #+#    #+#             */
/*   Updated: 2025/10/24 17:08:20 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size - 1)
	{
		if (a->arr[i] > a->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	print_op(const char *s)
{
	if (SILENT)
		return ;
	while (*s)
		write(1, s++, 1);
}

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_stack *s)
{
	if (s && s->arr)
	{
		free(s->arr);
		s->arr = NULL;
	}
	s->size = 0;
	s->capacity = 0;
}
