/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 18:12:05 by bpichyal          #+#    #+#             */
/*   Updated: 2025/10/28 15:05:22 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	parse_args(int argc, char **argv, t_stack *a)
{
	if (argc < 2)
		return (0);
	a->capacity = argc - 1;
	a->size = 0;
	a->arr = malloc(sizeof(int) * a->capacity);
	if (!a->arr)
		exit_error();
	if (!process_args(a, argv, 1, argc))
	{
		free(a->arr);
		a->arr = NULL;
		return (0);
	}
	return (1);
}
