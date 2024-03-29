/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_both.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selmandemir <selmandemir@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:55:49 by muhademi          #+#    #+#             */
/*   Updated: 2024/03/12 00:54:31 by selmandemir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_both(t_stack **a, t_stack **b)
{
	if (!(*a) || !((*a)-> next))
		return ;
	if (!(*b) || !((*b)-> next))
		return ;
	swap_a(a, 'a', 0);
	swap_a(b, 'b', 0);
	ft_printf("ss\n");
}

void	rotate_both(t_stack **a, t_stack **b)
{
	if (!(*a) || !((*a)-> next))
		return ;
	if (!(*b) || !((*b)-> next))
		return ;
	rotate_a(a, 'a', 0);
	rotate_a(b, 'b', 0);
	ft_printf("rr\n");
}

void	reverse_rotate_both(t_stack **a, t_stack **b)
{
	if (!(*a) || !((*a)-> next))
		return ;
	if (!(*b) || !((*b)-> next))
		return ;
	reverse_rotate_a(a, 'a', 0);
	reverse_rotate_a(b, 'b', 0);
	ft_printf("rrr\n");
}
