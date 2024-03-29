/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selmandemir <selmandemir@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:55:49 by muhademi          #+#    #+#             */
/*   Updated: 2024/03/12 00:23:53 by selmandemir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	back_to_a(t_stack **b, t_stack **a)
{
	set_target_for_b(*b, *a);
	go_top_a(a, (*b)-> target);
	push_a(a, b, 'a');
}

void	set_target_for_b(t_stack *a, t_stack *b)
{
	t_stack	*temp_b;
	t_stack	*target;
	int		temp_best;

	while (a)
	{
		temp_best = INT_MAX;
		temp_b = b;
		while (temp_b)
		{
			if (temp_b->number > a->number
				&& temp_b->number < temp_best)
			{
				temp_best = temp_b->number;
				target = temp_b;
			}
			temp_b = temp_b->next;
		}
		if (temp_best == INT_MAX)
			a -> target = find_min_node(b);
		else
			a -> target = target;
		a = a -> next;
	}
}
