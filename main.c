/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 00:02:06 by asalmi            #+#    #+#             */
/*   Updated: 2024/05/24 22:07:03 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void ll()
// {
// 	system("leaks push_swap");
// }

void	append_to_stack(t_list **lst, int ac, char **av)
{
	t_list	*new;
	char	**arg;
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		arg = ft_split(av[i], ' ');
		while (arg[j])
		{
			new = ft_lstnew(ft_atoi(arg[j]));
			new->index = -1;
			ft_lstadd_back(lst, new);
			j++;
		}
		free_array(arg);
		i++;
	}
	index_stack(lst);
}

void	lets_sort(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == 2)
		sa(a);
	else if (ft_lstsize(*a) == 3)
		sort_three(a);
	else if (ft_lstsize(*a) == 4)
		sort_four(a, b); 
	else if (ft_lstsize(*a) == 5)
		sort_five(a, b);
	else if (ft_lstsize(*a) <= 100)
		sort_range(a, b, 0, 15);
	else if (ft_lstsize(*a) > 100 && ft_lstsize(*a) <= 500)
		sort_range(a, b, 0, 35);
	else
		sort_range(a, b, 0, 45);
}

int	main(int ac, char **av)
{
	t_list	**a;
	t_list	**b;

	// atexit(ll);
	if (ac == 1)
		return (1);
	check_args(ac, av);
	a = (t_list **)malloc(sizeof(t_list));
	b = (t_list **)malloc(sizeof(t_list));
	*a = NULL;
	*b = NULL;
	append_to_stack(a, ac, av);
	is_duplicated(a);
	if (!is_sorted(a))
		lets_sort(a, b);
	free_stack(a);
	free_stack(b);
	free(a);
	free(b);
}
