/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:49:22 by bpichyal          #+#    #+#             */
/*   Updated: 2025/10/24 17:49:28 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	init_stacks(t_stack *a, t_stack *b, int ac, char **av)
{
	a->capacity = ac - 1;
	a->size = 0;
	a->arr = malloc(sizeof(int) * a->capacity);
	if (!a->arr)
		exit_error();
	b->capacity = a->capacity;
	b->size = 0;
	b->arr = malloc(sizeof(int) * b->capacity);
	if (!b->arr)
		exit_error();
	if (!process_args(a, av, 1, ac))
		exit_error();
	normalize_stack(a);
}

static int	read_line(char **line)
{
	char	buf[2];
	char	*tmp;
	int		rd;

	*line = NULL;
	while ((rd = read(STDIN_FILENO, buf, 1)) == 1)
	{
		buf[1] = '\0';
		if (buf[0] == '\n')
			return (1);
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	char	*line;

	if (ac < 2)
		return (0);
	init_stacks(&a, &b, ac, av);
	while (read_line(&line))
	{
		exec_op(&a, &b, line);
		free(line);
	}
	if (is_sorted(&a) && b.size == 0)
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}