/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   #+#+           */
/*   Created: 2025/08/05 15:55:00 by bpichyal          #+#    #+#             */
/*   Updated: 2025/08/05 15:55:00 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_valid_number(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	if (!str || !*str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		sign = 1;
		i++;
	}
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (sign && i == 1)
		return (0);
	return (1);
}

int	has_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*check;

	current = stack;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->value == check->value)
				return (1);
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}

int	ft_atoi_check(const char *str, int *result)
{
	long long	res;
	int			sign;
	int			i;

	res = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - '0');
		if (res * sign > INT_MAX || res * sign < INT_MIN)
			return (0);
		i++;
	}
	*result = (int)(res * sign);
	return (1);
}

int	parse_single_arg(char *arg, t_stack **a)
{
	char	**split;
	int		i;
	int		num;

	split = ft_split(arg, ' ');
	if (!split)
		return (0);
	i = 0;
	while (split[i])
	{
		if (!is_valid_number(split[i]) || !ft_atoi_check(split[i], &num))
		{
			ft_free_split(split);
			return (0);
		}
		add_node_back(a, new_node(num));
		i++;
	}
	ft_free_split(split);
	if (has_duplicates(*a))
	{
		free_stack(a);
		return (0);
	}
	assign_indices(*a);
	return (1);
}

int	parse_multiple_args(int argc, char **argv, t_stack **a)
{
	int	i;
	int	num;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]) || !ft_atoi_check(argv[i], &num))
			return (0);
		add_node_back(a, new_node(num));
		i++;
	}
	if (has_duplicates(*a))
	{
		free_stack(a);
		return (0);
	}
	assign_indices(*a);
	return (1);
}

int	parse_input(int argc, char **argv, t_stack **a)
{
	if (argc == 2)
		return (parse_single_arg(argv[1], a));
	else if (argc > 2)
		return (parse_multiple_args(argc, argv, a));
	return (0);
}

void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
