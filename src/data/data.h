

#ifndef DATA_H
#define DATA_H
#include "../push_swap.h"

void push_stack(t_stack *stack, int index, int data);
int pop_stack(t_stack *stack);
void free_stack(t_stack *stack);
void ft_freedom(char **dst);

#endif