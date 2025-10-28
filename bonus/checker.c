/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:49:22 by bpichyal          #+#    #+#             */
/*   Updated: 2025/10/28 15:15:15 by bpichyal         ###   ########.fr       */
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
}

static char	*read_line(void)
{
	char	buf[2];
	char	*line;
	char	*tmp;
	int		rd;

	line = NULL;
	rd = read(STDIN_FILENO, buf, 1);
	while (rd > 0)
	{
		buf[rd] = '\0';
		if (buf[0] == '\n')
			break ;
		tmp = line;
		line = ft_strjoin(line, buf);
		free(tmp);
		rd = read(STDIN_FILENO, buf, 1);
	}
	return (line);
}

static int	handle_line(t_stack *a, t_stack *b, char *line)
{
	if (*line == '\0')
	{
		free(line);
		return (0);
	}
	if (!exec_op(a, b, line))
	{
		write(2, "Error\n", 6);
		free(line);
		free_stack(a);
		free_stack(b);
		exit(EXIT_FAILURE);
	}
	free(line);
	return (1);
}

static void	execute_input(t_stack *a, t_stack *b)
{
	char	*line;
	int		executed;

	executed = 0;
	while (1)
	{
		line = read_line();
		if (!line)
			break ;
		executed += handle_line(a, b, line);
	}
	if (!executed)
	{
		free_stack(a);
		free_stack(b);
		exit(0);
	}
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac < 2)
		return (0);
	init_stacks(&a, &b, ac, av);
	execute_input(&a, &b);
	if (is_sorted(&a) && b.size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
