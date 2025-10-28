/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 17:20:00 by bpichyal          #+#    #+#             */
/*   Updated: 2025/10/28 15:03:17 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

// Just a silent mode for checker
# ifdef CHECKER
#  define SILENT 1
# else
#  define SILENT 0
# endif

// Stack
typedef struct s_stack
{
	int	*arr;
	int	size;
	int	capacity;
}		t_stack;

// operations
void	do_sa(t_stack *a);
void	do_sb(t_stack *b);
void	do_ss(t_stack *a, t_stack *b);
void	do_pa(t_stack *a, t_stack *b);
void	do_pb(t_stack *a, t_stack *b);
void	do_ra(t_stack *a);
void	do_rb(t_stack *b);
void	do_rr(t_stack *a, t_stack *b);
void	do_rra(t_stack *a);
void	do_rrb(t_stack *b);
void	do_rrr(t_stack *a, t_stack *b);

// utils
int		is_sorted(t_stack *a);
void	print_op(const char *s);
void	exit_error(void);
void	free_stack(t_stack *s);

// sorting
void	sort_stack(t_stack *a, t_stack *b);
void	push_chunks(t_stack *a, t_stack *b, int chunk_size);
void	tiny_sort(t_stack *a);
void	tiny_sort_five(t_stack *a, t_stack *b);

// parsing
int		parse_args(int argc, char **argv, t_stack *a);
int		process_args(t_stack *a, char **argv, int start, int end);
int		check_overflow(long res, int sign);
int		parse_digits(char *str, int sign, long *res);
int		safe_atoi(char *str, int *out);
int		is_valid_number(char *s);
int		is_duplicate(t_stack *a, int val, int size);
void	normalize_stack(t_stack *a);

// helper functions for sorting
int		find_min_index(t_stack *s);
int		stack_max(t_stack *s);
int		stack_index(t_stack *s, int value);

// bonus checker
int		exec_op(t_stack *a, t_stack *b, char *line);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);

// bonus checker utils
int		ft_strcmp(const char *s1, const char *s2);
void	silent_rra(t_stack *a);
void	rra_silent(t_stack *a);

// just for checking bonus files

void	rra_silent(t_stack *a);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_strcmp(const char *s1, const char *s2);

#endif
