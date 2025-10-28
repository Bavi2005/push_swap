/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 15:49:55 by bpichyal          #+#    #+#             */
/*   Updated: 2025/10/28 15:05:13 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <limits.h>

int	ft_atoi(const char *str, int *error)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	*error = 0;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			*error = 1;
			return (0);
		}
		res = res * 10 + (*str++ - '0');
		if (res * sign > INT_MAX || res * sign < INT_MIN)
		{
			*error = 1;
			return (0);
		}
	}
	return ((int)(res * sign));
}

int	check_overflow(long res, int sign)
{
	if (res * sign > 2147483647 || res * sign < -2147483648)
		return (0);
	return (1);
}

int	parse_digits(char *str, int sign, long *res)
{
	int	digits;

	digits = 0;
	*res = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		*res = *res * 10 + (*str - '0');
		if (!check_overflow(*res, sign))
			return (0);
		digits++;
		str++;
	}
	if (digits == 0)
		return (0);
	return (1);
}

int	process_args(t_stack *a, char **argv, int start, int end)
{
	int	i;
	int	val;

	i = start;
	while (i < end)
	{
		if (!argv[i] || !is_valid_number(argv[i]))
			return (0);
		if (!safe_atoi(argv[i], &val))
			return (0);
		if (is_duplicate(a, val, a->size))
			return (0);
		a->arr[a->size] = val;
		a->size++;
		i++;
	}
	return (1);
}
