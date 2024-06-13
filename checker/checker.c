#include "../src/push_swap.h"

static void init(t_stack **stack_a, int *nb, int c)
{
    int i;
    t_stack *tmp;

    i = c - 1;
    while (i >= 0)
        (push_stack(&stack_a, 0, nb[i]), i--);
}

static void read_and_execute(t_stack **stack_a, t_stack **stack_b)
{
    char *str;

    while (1)
    {
        str = get_next_line(0);
        if (!str)
            break;
        else if (is_command(str))
            exeute_command(stack_a, stack_b, str);
        else
        {
            write(1, "Error\n", 6);
            exit(0);
        }
    }
}

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int count;
    int *numbers;

    stack_a = NULL;
    stack_b = NULL;
    // Guardar en el stack a, los argumentos pasados por la terminal
    count = check_digits(argc, argv);
    numbers = parse(argc, argv, count);
    if (count <= 1 || checkd_bf(numbers, count))
    {
        free(numbers);
        if (count == 1)
            display_error("Error: Un numero", 1);
        display_error("Error: Numeros repetidos", 1);
    }
    init(&stack_a, numbers, count);
    // Bucle que pida los movimientos y los ejecute
    read_and_execute(&stack_a, &stack_b);
    free(numbers);
    free_stack(stack_a);
    if (is_sorted(stack_a))
        write(1, "OK\n", 3);
}
