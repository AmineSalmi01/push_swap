/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 00:01:48 by asalmi            #+#    #+#             */
/*   Updated: 2024/05/24 21:35:52 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	find_distance(t_list **stack, int data)
{
	int		distance;
	t_list	*head;

	head = *stack;
	distance = 0;
	while (head != NULL)
	{
		if (head->data == data)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}
