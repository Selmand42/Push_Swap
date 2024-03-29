/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhademi <muhademi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:55:49 by muhademi          #+#    #+#             */
/*   Updated: 2024/03/29 19:56:42 by muhademi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int					number;
	int					index;
	int					cost;
	int					cheapest;
	struct s_stack		*target;
	struct s_stack		*next;
}	t_stack;

void	set_target_for_b(t_stack *a, t_stack *b);
void	ft_add_back(t_stack **stack, t_stack *stack_new);
void	ft_free(t_stack **lst);
t_stack	*ft_stack_new(int content);
int		ft_find_index(t_stack *a, int number);
t_stack	*ft_lstlast(t_stack *lst);
int		ft_lstsize(t_stack **lst);
int		ft_stack_min(t_stack *a);
int		ft_stack_max(t_stack *a);
int		ft_error(void);
int		check_string(char *str);
t_stack	*fill_stack_a(int argc, char **argv);
t_stack	*str_to_stack(char *str);
void	fill_stack(t_stack **node, char **numbers);
t_stack	*arr_to_stack(int count, char **arr);
int		check_dup(t_stack **node);
int		check_sorted(t_stack **node);
void	swap_a(t_stack **a, char c, int cond);
void	push_a(t_stack **a, t_stack **b, char c);
void	rotate_a(t_stack **a, char c, int cond);
void	reverse_rotate_a(t_stack **a, char c, int cond);
void	swap_both(t_stack **a, t_stack **b);
void	rotate_both(t_stack **a, t_stack **b);
void	reverse_rotate_both(t_stack **a, t_stack **b);
int		ft_find_index(t_stack *a, int number);
void	sort_three(t_stack **a);
void	sort(t_stack **a);
void	pop_a_to_b(t_stack **a, t_stack **b, char c);
void	set_index(t_stack **a);
void	set_target(t_stack *a, t_stack *b);
void	find_cheapest(t_stack *a);
t_stack	*find_min_node(t_stack *stack);
t_stack	*find_max_node(t_stack *stack);
t_stack	*get_cheapest(t_stack *a);
void	prepare_to_push_a(t_stack **a, t_stack **b);
void	go_top(t_stack **a, t_stack **b, t_stack *num_a, t_stack *num_b);
void	go_top_b(t_stack **a, t_stack *num_a);
void	go_top_a(t_stack **a, t_stack *num_a);
void	set_cost(t_stack *a);
void	back_to_a(t_stack **b, t_stack **a);

#endif
