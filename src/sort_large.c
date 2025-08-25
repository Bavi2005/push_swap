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

	printf("Calculating median...\n");
	printf("Values for median calculation: ");
	for (int k = 0; k < size; k++)
		printf("%d ", arr[k]);
	printf("\n");
	i = 1;
	while (i < size)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		i++;
	}

	median = arr[size / 2];
	printf("Calculated median: %d\n", median);
	free(arr);
	return (median);
}

static void	push_chunk_to_b(t_stack **a, t_stack **b, int chunk_size)
{
	int	pushed;
	int	median;
	int	stack_size_val;

	pushed = 0;
	stack_size_val = stack_size(*a);
	median = get_median(*a, stack_size_val);
	
	while (pushed < chunk_size && *a)
	{
		printf("Pushing value: %d, Median: %d\n", (*a)->value, median);
		if ((*a)->value < median)
		{
			pb(a, b);
			pushed++;
		}
		else
		{
			ra(a);
		}
	}
}

static void	push_back_to_a(t_stack **a, t_stack **b)
{
	while (*b)
	{
		int max_val = get_max(*b);
		int max_pos = get_position(*b, max_val);
		int stack_size_b = stack_size(*b);
		
		// Rotate to bring max to top of B
		if (max_pos <= stack_size_b / 2)
		{
			while ((*b)->value != max_val)
				rb(b);
		}
		else
		{
			while ((*b)->value != max_val)
				rrb(b);
		}
		
		pa(a, b);
	}
}

void	sort_large(t_stack **a, t_stack **b)
{
	int	total_size;
	int	chunk_size;
	int	chunk_count;
	int	i;

	total_size = stack_size(*a);
	if (total_size <= 5)
	{
		if (total_size == 2)
			sort_two(a);
		else if (total_size == 3)
			sort_three(a);
		else if (total_size == 4)
			sort_four(a, b);
		else if (total_size == 5)
			sort_five(a, b);
		return;
	}

	// Determine chunk size based on total size
	if (total_size <= 100)
		chunk_size = total_size / 3;
	else
		chunk_size = total_size / 11;
	
	chunk_count = (total_size + chunk_size - 1) / chunk_size;
	
	// Push chunks to stack B
	for (i = 0; i < chunk_count; i++)
	{
		int remaining = total_size - i * chunk_size;
		int current_chunk_size = (remaining < chunk_size) ? remaining : chunk_size;
		push_chunk_to_b(a, b, current_chunk_size);
	}

	// Push back to A in sorted order
	push_back_to_a(a, b);
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
