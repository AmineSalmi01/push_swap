/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:17:30 by asalmi            #+#    #+#             */
/*   Updated: 2024/05/23 19:23:37 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_list **stack)
{
	t_list	*first_node;
	t_list	*second_node;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	first_node = *stack;
	second_node = (*stack)->next;
	first_node->next = second_node->next;
	second_node->next = first_node;
	*stack = second_node;
}

void	sa(t_list **a)
{
	swap(a);
}

void	sb(t_list **b)
{
	swap(b);
}

void	ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
}
