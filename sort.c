/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selmandemir <selmandemir@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:55:49 by muhademi          #+#    #+#             */
/*   Updated: 2024/03/12 20:41:51 by selmandemir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack **a)
{
	t_stack	*b;

	if (ft_lstsize(a) == 2)
		swap_a(a, 'a', 1);
	else if (ft_lstsize(a) == 3)
		sort_three(a);
	else
	{
		b = (*a);
		(*a) = (*a)-> next;
		b -> next = 0;
		ft_printf("pb\n");
		if (ft_lstsize(a) > 3 && !check_sorted(a))
			push_a(&b, a, 'b');
		while (ft_lstsize(a) > 3 && !check_sorted(a))
			pop_a_to_b(a, &b, 'b');
		sort_three(a);
		while (ft_lstsize(&b))
			back_to_a(&b, a);
		go_top_a(a, find_min_node(*a));
	}
}

void	sort_three(t_stack **a)
{
	if (check_sorted(a))
		return ;
	if (ft_stack_min(*a) == (*a)-> number)
	{
		reverse_rotate_a((a), 'a', 1);
		swap_a(a, 'a', 1);
	}
	else if (ft_stack_max((*a)) == (*a)-> number)
	{
		rotate_a((a), 'a', 1);
		if (!check_sorted(a))
			swap_a(a, 'a', 1);
	}
	else if (ft_find_index((*a), ft_stack_max((*a))) == 1)
		reverse_rotate_a((a), 'a', 1);
	else
		swap_a((a), 'a', 1);
}
