/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:14:28 by asalmi            #+#    #+#             */
/*   Updated: 2024/05/23 19:22:01 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
}

void	pb(t_list **b, t_list **a)
{
	push(b, a);
}
