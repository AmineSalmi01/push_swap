/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 00:02:28 by asalmi            #+#    #+#             */
/*   Updated: 2024/05/23 18:02:57 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack)
{
	int	highest;

	highest = find_highest(*stack);
	if ((*stack)->data == highest)
		ra(stack);
	else if ((*stack)->next->data == highest)
		rra(stack);
	if ((*stack)->data > (*stack)->next->data)
		sa(stack);
}

void	sort_four(t_list **a, t_list **b)
{
	int	distance;

	distance = find_distance(a, find_min(a));
	if (distance == 1)
		sa(a);
	else if (distance == 2)
	{
		ra(a);
		ra(a);
	}
	else if (distance == 3)
		rra(a);
	if (is_sorted(a))
		return ;
	pb(b, a);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_list **a, t_list **b)
{
	int	distance;

	distance = find_distance(a, find_min(a));
	if (distance == 1)
		ra(a);
	else if (distance == 2)
	{
		ra(a);
		ra(a);
	}
	else if (distance == 3)
	{
		rra(a);
		rra(a);
	}
	else if (distance == 4)
		rra(a);
	if (is_sorted(a))
		return ;
	pb(b, a);
	sort_four(a, b);
	pa(a, b);
}

static void	push_all_in_a(t_list **a, t_list **b)
{
	int	index;
	int	size;

	while (*b)
	{
		index = find_max_index(*b);
		size = ft_lstsize(*b) / 2;
		if (index == 0)
			pa(a, b);
		else if (index >= size)
			rrb(b);
		else if (index < size)
			rb(b);
	}
}

void	sort_range(t_list **a, t_list **b, int start, int end)
{
	while (*a)
	{
		if ((*a)->index >= start && (*a)->index <= end)
		{
			pb(b, a);
			start++;
			end++;
		}
		else if ((*a)->index < start)
		{
			pb(b, a);
			rb(b);
			start++;
			end++;
		}
		else
			ra(a);
	}
	push_all_in_a(a, b);
}
