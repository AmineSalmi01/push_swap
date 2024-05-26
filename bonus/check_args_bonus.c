/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:53:11 by asalmi            #+#    #+#             */
/*   Updated: 2024/05/23 19:06:00 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	is_duplicated(t_list **stack)
{
	t_list	*tmp;
	t_list	*current;

	current = *stack;
	if (stack == NULL)
		return ;
	while (current)
	{
		tmp = current->next;
		while (tmp)
		{
			if (current->data == tmp->data)
				ft_put_error("Error\n", 2);
			tmp = tmp->next;
		}
		current = current->next;
	}
}

static int	is_number(char *av)
{
	int	i;

	i = 0;
	if (ft_sign(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i])
	{
		if (!ft_digit(av[i]) && av[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	check_args(int ac, char **av)
{
	int		i;
	char	**arg;
	int		j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		arg = ft_split(av[i], ' ');
		while (arg[j])
		{
			if (!is_number(arg[j]))
				ft_put_error("Error\n", 2);
			j++;
		}
		free_array(arg);
		i++;
	}
}
