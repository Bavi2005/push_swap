/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 18:06:41 by bpichyal          #+#    #+#             */
/*   Updated: 2025/10/24 17:08:31 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	if (!parse_args(argc, argv, &a))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	b.arr = malloc(sizeof(int) * a.capacity);
	if (!b.arr)
		exit_error();
	b.size = 0;
	b.capacity = a.capacity;
	normalize_stack(&a);
	sort_stack(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
