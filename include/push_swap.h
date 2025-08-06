#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

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

#endif
