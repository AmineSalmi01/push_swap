/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:32:18 by asalmi            #+#    #+#             */
/*   Updated: 2024/05/23 18:57:59 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
			ft_put_error("Error\n", 2);
		str++;
	}
	return (res * sign);
}
