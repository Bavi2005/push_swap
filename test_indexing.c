#include "../include/push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    t_stack *a = NULL;

    if (!parse_input(argc, argv, &a))
    {
        printf("Error in input\n");
        return 1;
    }

    assign_indices(a);

    // Print the stack to verify indices
    t_stack *current = a;
    while (current)
    {
        printf("Value: %d, Index: %d\n", current->value, current->index);
        current = current->next;
    }

    free_stack(&a);
    return 0;
}
