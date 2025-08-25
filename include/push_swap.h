/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:23:25 by bpichyal          #+#    #+#             */
/*   Updated: 2025/08/25 16:12:37 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

#include "libft/libft.h"

typedef struct s_stack
{
	int value;
	int index;
	struct s_stack *next;
} t_stack;

int parse_input(int argc, char **argv, t_stack **a);
int ft_printf(const char *format, ...);
void free_stack(t_stack **stack);
int is_sorted(t_stack *stack);
int stack_size(t_stack *stack);
void sort_two(t_stack **a);
void sort_three(t_stack **a);
void sort_four(t_stack **a, t_stack **b);
void sort_five(t_stack **a, t_stack **b);
void sort_large(t_stack **a, t_stack **b);
int get_position(t_stack *stack, int value);
t_stack *get_last(t_stack *stack);

// Additional function declarations
t_stack *new_node(int value);
void add_node_back(t_stack **stack, t_stack *new_node);
int is_valid_number(char *str);
int has_duplicates(t_stack *stack);
int ft_atoi_check(const char *str, int *result);
int parse_single_arg(char *arg, t_stack **a);
int parse_multiple_args(int argc, char **argv, t_stack **a);
void ft_free_split(char **split);

// Stack operation functions
void sa(t_stack **a);
void sb(t_stack **b);
void ss(t_stack **a, t_stack **b);
void pa(t_stack **a, t_stack **b);
void pb(t_stack **a, t_stack **b);
void ra(t_stack **a);
void rb(t_stack **b);
void rr(t_stack **a, t_stack **b);
void rra(t_stack **a);
void rrb(t_stack **b);
void rrr(t_stack **a, t_stack **b);

// Utility functions
int get_min(t_stack *stack);
int get_max(t_stack *stack);
int get_position(t_stack *stack, int value);
void assign_indices(t_stack *stack);

#endif
