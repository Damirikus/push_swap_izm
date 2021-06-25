#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		number_of_arg;
	t_list	*stack_a;
    // int i;
	// char	**massivforsplit;
	// int		k;

    number_of_arg = ft_number_of_arguments(argc, argv);
    ft_cheking_and_init_stack(&stack_a, argc, argv, number_of_arg);
        
	// if (!ft_distributor(&stack_a))
		// ft_errors(1);
	return (0);
}

void	ft_errors(int a)
{
	(void)a;
	write(1, "Error\n", 6);
	exit(1);
}

int ft_number_of_arguments(int argc, char **argv)
{
    int i;
    int k;
    char	**massivforsplit;
    int number;
    number = 0;
    i = 1;
    while (i < argc)
	{
		massivforsplit = ft_split(argv[i], ' ');
		k = 0;
		while (massivforsplit[k])
		{
			k++;
            number++;
            free(massivforsplit[k]);
		}
        free(massivforsplit);
		i++;
	}
    return (number);
}

void ft_cheking_and_init_stack(t_list **stack_a, int argc, char **argv, int len)
{
    char **massivforsplit;
    int i;
    int *array_for_orders;
    int k;
    int count;
    array_for_orders = malloc(sizeof(int) * (len + 1));
    if (!array_for_orders)
         ft_errors(1);
    i = 1;
    count = 0;
	while (i < argc)
	{
		massivforsplit = ft_split(argv[i], ' ');
		k = 0;
		while (massivforsplit[k])
		{
			if (!ft_chek(massivforsplit[k], stack_a, array_for_orders, count))
				 ft_errors(1);
			free(massivforsplit[k]);
			k++;
            count++;
		}
		free(massivforsplit);
		i++;
	}
    i = 0;
    while (i < len)
    {
        printf("array = %d\n", array_for_orders[i]);
        i++;
    }
    // ft_init_chek_sort_stack_array();
}







int	ft_distributor(t_list **stack_a)
{
	t_list	*stack_b;
	int		len;
	int		*massfororder;
	int		i;
	t_list	*current;

	current = *stack_a;
	len = ft_lstsize(*stack_a);
	massfororder = (int *) malloc(len + 1);
	if (!massfororder)
		return (0);
	ft_bzero(massfororder, len);
	i = 0;
	while (current)
	{
		massfororder[i] = (int) current->content;
		i++;
		current = current->next;
	}
	massfororder[i] = '\0';
	if (ft_masscheck(massfororder, len))
		return (1);
	ft_disti(massfororder, stack_a, &stack_b, len);
	return (1);
}

void	ft_disti(int *massfororder, t_list **stack_a, t_list **stack_b, int len)
{
	sort_mass(massfororder, stack_a, len);
	if (len <= 5)
		ft_to_5(stack_a, stack_b, len);
	else
		ft_first(stack_a, stack_b);
	free(massfororder);
}

void	sort_mass(int *massfororder, t_list **stack_a, int len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (massfororder[i])
		i++;
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len - (i + 1))
		{
			if (massfororder[j] > massfororder[j + 1])
			{
				temp = massfororder[j];
				massfororder[j] = massfororder[j + 1];
				massfororder[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	init_orders(massfororder, stack_a, len);
}
