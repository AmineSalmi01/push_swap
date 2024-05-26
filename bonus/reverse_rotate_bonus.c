/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:16:34 by asalmi            #+#    #+#             */
/*   Updated: 2024/05/23 19:22:45 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*second_to_last;
	int		size;

	size = ft_lstsize(*stack);
	if (stack == NULL || *stack == NULL || size == 1)
		return ;
	last = ft_lstlast(*stack);
	second_to_last = get_second_to_last(*stack);
	if (second_to_last)
		second_to_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_list **a)
{
	reverse_rotate(a);
}

void	rrb(t_list **b)
{
	reverse_rotate(b);
}

void	rrr(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
