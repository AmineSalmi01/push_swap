/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 00:02:15 by asalmi            #+#    #+#             */
/*   Updated: 2024/05/27 16:24:54 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list {
	int				data;
	int				index;
	struct s_list	*next;
}				t_list;

void	check_args(int ac, char **av);
void	is_duplicated(t_list **stack);

char	**ft_split(const char *s, char c);
long	ft_atoi(const char *str);

void	print_error(void);
int		ft_digit(char c);
int		ft_sign(char c);

t_list	*ft_lstnew(int data);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*get_second_to_last(t_list *stack);

int		is_sorted(t_list **stack);

void	pa(t_list **a, t_list **b);
void	pb(t_list **b, t_list **a);

void	ra(t_list **a);
void	rb(t_list **b);

void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

void	sa(t_list **a);
void	sb(t_list **b);

void	sort_three(t_list **stack);
void	sort_four(t_list **a, t_list **b);
void	sort_five(t_list **a, t_list **b);
void	sort_range(t_list **stack_a, t_list **stack_b, int start, int end);

void	free_stack(t_list **stack);
void	free_array(char **arg);

int		find_min(t_list **stack);
int		find_distance(t_list **stack, int index);
int		find_highest(t_list *stack);

void	index_stack(t_list **stack);
int		find_max_index(t_list *stack);

int		ft_strlen(const char *s);
int		len_word(const char *s, char c);
char	*ft_substr(const char *s, int start, int len);

#endif