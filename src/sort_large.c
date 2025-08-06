/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   #+#+           */
/*   Created: 2025/08/05 16:05:00 by bpichyal          #+#    #+#             */
/*   Updated: 2025/08/05 16:05:00 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	get_median(t_stack *stack, int size)
{
	int		*arr;
	int		i;
	t_stack	*tmp;
	int		median;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (0);
	tmp = stack;
	i = 0;
	while (tmp && i < size)
	{
		arr[i++] = tmp->value;
		tmp = tmp->next;
	}
	// Simple bubble sort for median
	i = 0;
	while (i < size - 1)
	{
		int j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	median = arr[size / 2];
	free(arr);
	return (median);
}

static void	push_less_than_median(t_stack **a, t_stack **b, int median, int *pushed)
{
	while (*a && *pushed < 3)
	{
		if ((*a)->value < median)
		{
			pb(a, b);
			(*pushed)++;
		}
		else
			ra(a);
	}
}

static void	sort_three_back(t_stack **a, t_stack **b)
{
	while (*b)
	{
		pa(a, b);
	}
}


void	sort_large(t_stack **a, t_stack **b)
{
	int	median;
	int	pushed;

	if (stack_size(*a) <= 5)
	{
		if (stack_size(*a) == 4)
			sort_four(a, b);
		else if (stack_size(*a) == 5)
			sort_five(a, b);
		return;
	}
	
	median = get_median(*a, stack_size(*a));
	pushed = 0;
	push_less_than_median(a, b, median, &pushed);
	sort_three(a);
	sort_three_back(a, b);
}

void	rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
}

void	rev_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
}
