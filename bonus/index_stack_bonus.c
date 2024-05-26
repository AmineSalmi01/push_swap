/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 00:01:54 by asalmi            #+#    #+#             */
/*   Updated: 2024/05/23 19:09:00 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static t_list	*get_next_min(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int		flg;

	flg = 0;
	min = NULL;
	head = *stack;
	while (head)
	{
		if ((head->index == -1) && (flg == 0 || head->data < min->data))
		{
			min = head;
			flg = 1;
		}
		head = head->next;
	}
	return (min);
}

void	index_stack(t_list **stack)
{
	int		index;
	t_list	*head;

	head = get_next_min(stack);
	index = 0;
	while (head)
	{
		head->index = index++;
		head = get_next_min(stack);
	}
}
