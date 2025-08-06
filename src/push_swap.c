/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   #+#+           */
/*   Created: 2025/08/05 15:40:00 by bpichyal          #+#    #+#             */
/*   Updated: 2025/08/05 15:40:00 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (!parse_input(argc, argv, &a))
	{
		ft_printf("Error\n");
		free_stack(&a);
		return (1);
	}
	if (is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	if (stack_size(a) == 2)
		sort_two(&a);
	else if (stack_size(a) == 3)
		sort_three(&a);
	else if (stack_size(a) == 4)
		sort_four(&a, &b);
	else if (stack_size(a) == 5)
		sort_five(&a, &b);
	else
		sort_large(&a, &b);
	free_stack(&a);
	return (0);
}
