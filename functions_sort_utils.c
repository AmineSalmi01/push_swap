/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_sort_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:38:38 by asalmi            #+#    #+#             */
/*   Updated: 2024/05/23 17:44:37 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	find_min(t_list **stack)
{
	int		min_data;
	t_list	*head;

	head = *stack;
	min_data = head->data;
	while (head != NULL)
	{
		if (head->data < min_data)
			min_data = head->data;
		head = head->next;
	}
	return (min_data);
}

int	find_highest(t_list *stack)
{
	int	max;

	max = INT_MIN;
	if (stack == NULL)
		return (0);
	while (stack)
	{
		if (stack->data > max)
			max = stack->data;
		stack = stack->next;
	}
	return (max);
}

int	is_sorted(t_list **stack)
{
	t_list	*head;

	head = *stack;
	if (stack == NULL || *stack == NULL)
		return (1);
	while (head->next)
	{
		if (head->data > head->next->data)
			return (0);
		head = head->next;
	}
	return (1);
}
