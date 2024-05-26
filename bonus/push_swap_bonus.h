/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 21:52:44 by asalmi            #+#    #+#             */
/*   Updated: 2024/05/23 21:30:38 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "./get_next_line/get_next_line.h"
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list {
	int				data;
	int				index;
	struct s_list	*next;
}				t_list;

void	pa(t_list **a, t_list **b);
void	pb(t_list **b, t_list **a);

void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);

void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);

t_list	*ft_lstnew(int data);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*get_second_to_last(t_list *stack);

long	ft_atoi(const char *str);
char	**ft_split(const char *s, char c);

void	index_stack(t_list **stack);

void	free_stack(t_list **stack);
void	free_array(char **arg);

void	check_args(int ac, char **av);
void	is_duplicated(t_list **stack);

int		find_distance(t_list **stack, int data);
int		find_max_index(t_list *stack);
int		find_min(t_list **stack);
int		find_highest(t_list *stack);

int		ft_digit(char c);
int		ft_sign(char c);

int		is_sorted(t_list **stack);

int		ft_strcmp(const char *s1, const char *s2);
int		ft_strlen(const char *s);
void	ft_put_error(char *s, int fd);

char	*ft_substr(const char *s, int start, int len);
int		count_words(const char *s, char c);

#endif
