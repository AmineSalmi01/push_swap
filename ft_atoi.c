/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:32:18 by asalmi            #+#    #+#             */
/*   Updated: 2024/05/23 17:41:43 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *str)
{
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		sign = 1 - 2 * (*str == '-');
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + *str - 48;
		if ((res * sign) > 2147483647 || (res * sign) < -2147483648)
			print_error();
		str++;
	}
	return (res * sign);
}
