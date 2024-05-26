/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 00:01:51 by asalmi            #+#    #+#             */
/*   Updated: 2024/05/23 19:06:45 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	len_word(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	cleanup_word_array(char **result, int i)
{
	while (i > 0)
	{
		i--;
		free(result[i]);
	}
	free(result);
}

static char	**alocated_word(const char *s, char c, char **result, int words)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < words)
	{
		while (s[j] && s[j] == c)
			j++;
		result[i] = ft_substr(s, j, len_word(&s[j], c));
		if (!result[i])
		{
			cleanup_word_array(result, i);
			return (NULL);
		}
		while (s[j] && s[j] != c)
			j++;
		i++;
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	int		wc;

	if (!s)
		return (NULL);
	wc = count_words(s, c);
	if (wc == 0)
		ft_put_error("Error\n", 2);
	result = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!result)
		return (NULL);
	result = alocated_word(s, c, result, wc);
	if (!result)
	{
		free(result);
		return (NULL);
	}
	return (result);
}
