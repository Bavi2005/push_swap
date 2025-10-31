/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:51:06 by bpichyal          #+#    #+#             */
/*   Updated: 2025/10/31 17:14:10 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_valid_number(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		i++;
		if (!s[i])
			return (0);
	}
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate(t_stack *a, int val, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (a->arr[i] == val)
			return (1);
		i++;
	}
	return (0);
}

int	safe_atoi(char *str, int *out)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	if (!*str)
		return (0);
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!parse_digits(str, sign, &res))
		return (0);
	if (res == 0 && *str == '0')
		*out = 0;
	else
		*out = (int)(res * sign);
	return (1);
}
