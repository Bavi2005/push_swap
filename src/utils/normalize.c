/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 17:20:00 by bpichyal          #+#    #+#             */
/*   Updated: 2025/10/24 17:07:49 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	*copy_array(t_stack *a)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * a->size);
	if (!arr)
		exit_error();
	i = 0;
	while (i < a->size)
	{
		arr[i] = a->arr[i];
		i++;
	}
	return (arr);
}

static void	selection_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	normalize_stack(t_stack *a)
{
	int	*copy;
	int	i;
	int	j;

	copy = copy_array(a);
	selection_sort(copy, a->size);
	i = 0;
	while (i < a->size)
	{
		j = 0;
		while (j < a->size)
		{
			if (a->arr[i] == copy[j])
			{
				a->arr[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(copy);
}
