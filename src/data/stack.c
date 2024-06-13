
#include "data.h"

void push_stack(t_stack **stack, int index, int data)
{
    t_stack *tmp;

    tmp = (t_stack *)malloc(sizeof(t_stack));
    if (!tmp)
        return;
    tmp->data = data;
    tmp->s_index = index;
    tmp->next = *stack;
    *stack = tmp;
    // printf("stack_a data: %d | index: %d | data.supposed: %d\n", stack->data, stack->s_index, data);
}

int pop_stack(t_stack **stack)
{
    t_stack *top;
    int data;

    if (!stack)
        exit(1);
    top = *stack;
    data = top->data;
    *stack = top->next;
    free(top);
    top = NULL;
    return (data);
}

void free_stack(t_stack *stack)
{
    while (stack)
        pop_stack(&stack);
}

void ft_freedom(char **dst)
{
    size_t n_word;

    n_word = 0;
    while (dst[n_word])
        free(dst[n_word++]);
    free(dst);
}
