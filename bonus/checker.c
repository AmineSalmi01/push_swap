/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:21:44 by asalmi            #+#    #+#             */
/*   Updated: 2024/05/24 18:50:11 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	check_command(t_list **a, t_list **b, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		sa(a);
	else if (!ft_strcmp(line, "sb\n"))
		sb(b);
	else if (!ft_strcmp(line, "ss\n"))
		ss(a, b);
	else if (!ft_strcmp(line, "pa\n"))
		pa(a, b);
	else if (!ft_strcmp(line, "pb\n"))
		pb(b, a);
	else if (!ft_strcmp(line, "rra\n"))
		rra(a);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(b);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(a, b);
	else if (!ft_strcmp(line, "ra\n"))
		ra(a);
	else if (!ft_strcmp(line, "rb\n"))
		rb(b);
	else if (!ft_strcmp(line, "rr\n"))
		rr(a, b);
	else
		ft_put_error("Error\n", 2);
}

void	confirm_sorting(t_list **a, t_list **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		check_command(a, b, line);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(a) && ft_lstsize(*b) == 0)
		write(1, "OK\n", 3);
	else
	{
		free_stack(a);
		ft_put_error("KO\n", 1);
	}
}

int	main(int ac, char **av)
{
	t_list	**a;
	t_list	**b;

	if (ac == 1)
		return (1);
	check_args(ac, av);
	a = (t_list **)malloc(sizeof(t_list));
	b = (t_list **)malloc(sizeof(t_list));
	*a = NULL;
	*b = NULL;
	append_to_stack(a, ac, av);
	is_duplicated(a);
	confirm_sorting(a, b);
	free_stack(a);
	free_stack(b);
	free(a);
	free(b);
}
