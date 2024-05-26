/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:15:38 by asalmi            #+#    #+#             */
/*   Updated: 2024/05/23 19:22:53 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*last;
	int		size;

	size = ft_lstsize(*stack);
	if (stack == NULL || *stack == NULL || size == 1)
		return ;
	head = *stack;
	last = ft_lstlast(*stack);
	last->next = head;
	*stack = head->next;
	head->next = NULL;
}

void	ra(t_list **a)
{
	rotate(a);
}

void	rb(t_list **b)
{
	rotate(b);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
}
