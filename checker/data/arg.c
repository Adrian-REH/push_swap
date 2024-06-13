#include "../src/push_swap.h"
#include "../src/commands/commands.h"

void exeute_command(t_stack **a_bonus, t_stack **b_bonus, char *str)
{
    if (ft_strncmp(str, "pb\n", 3) == 0)
        push(b_bonus, a_bonus, NULL);
    else if (ft_strncmp(str, "pa\n", 3) == 0)
        push(a_bonus, b_bonus, NULL);
    else if (ft_strncmp(str, "ra\n", 3) == 0)
        rotate(a_bonus, NULL, NULL);
    else if (ft_strncmp(str, "rb\n", 3) == 0)
        rotate(b_bonus, NULL, NULL);
    else if (ft_strncmp(str, "rr\n", 3) == 0)
        rotate(a_bonus, b_bonus, NULL);
    else if (ft_strncmp(str, "rra\n", 4) == 0)
        rev_rotate(a_bonus, NULL, NULL);
    else if (ft_strncmp(str, "rrb\n", 4) == 0)
        rev_rotate(b_bonus, NULL, NULL);
    else if (ft_strncmp(str, "rrr\n", 4) == 0)
        rev_rotate(a_bonus, b_bonus, NULL);
    else if (ft_strncmp(str, "sa\n", 3) == 0)
        swap(a_bonus, NULL, NULL);
    else if (ft_strncmp(str, "sb\n", 3) == 0)
        swap(b_bonus, NULL, NULL);
    else if (ft_strncmp(str, "ss\n", 3) == 0)
        swap(a_bonus, b_bonus, NULL);
}

int is_command(char *str)
{
    int flag;

    flag = 0;
    if (ft_strncmp(str, "pb\n", 3) == 0 || ft_strncmp(str, "pa\n", 3) == 0)
        flag = 1;
    else if (ft_strncmp(str, "ra\n", 3) == 0 || ft_strncmp(str, "rb\n", 3) == 0)
        flag = 1;
    else if (ft_strncmp(str, "rr\n", 3) == 0)
        flag = 1;
    else if (ft_strncmp(str, "rra\n", 4) == 0 || ft_strncmp(str, "rrb\n", 4) == 0)
        flag = 1;
    else if (ft_strncmp(str, "rrr\n", 4) == 0)
        flag = 1;
    else if (ft_strncmp(str, "sa\n", 3) == 0)
        flag = 1;
    else if (ft_strncmp(str, "sb\n", 3) == 0)
        flag = 1;
    else if (ft_strncmp(str, "ss\n", 3) == 0)
        flag = 1;
    return (flag);
}