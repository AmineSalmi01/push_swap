/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:16:41 by asalmi            #+#    #+#             */
/*   Updated: 2024/05/23 18:22:54 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **dst, t_list **src)
{
	t_list	*head_src;

	if (ft_lstsize(*src) == 0)
		return ;
	head_src = *src;
	*src = (*src)->next;
	if (*dst == NULL)
	{
		*dst = head_src;
		head_src->next = NULL;
	}
	else
	{
		head_src->next = *dst;
		*dst = head_src;
	}
}

void	pa(t_list **a, t_list **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_list **b, t_list **a)
{
	push(b, a);
	write(1, "pb\n", 3);
}
