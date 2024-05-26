/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 00:01:48 by asalmi            #+#    #+#             */
/*   Updated: 2024/05/24 21:36:15 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sign(char c)
{
	return (c == '-' || c == '+');
}

int	ft_digit(char c)
{
	return (c >= 48 && c <= 57);
}

void	free_stack(t_list **stack)
{
	t_list	*next;

	if (stack == NULL || *stack == NULL)
		return ;
	while (*stack)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
	*stack = NULL;
}

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	find_max_index(t_list *stack)
{
	int	max_index;
	int	current_index;
	int	max_data;

	max_index = 0;
	current_index = 0;
	max_data = stack->data;
	while (stack)
	{
		if (stack->data > max_data)
		{
			max_data = stack->data;
			max_index = current_index;
		}
		current_index++;
		stack = stack->next;
	}
	return (max_index);
}
