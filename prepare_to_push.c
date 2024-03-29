/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_to_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selmandemir <selmandemir@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:55:49 by muhademi          #+#    #+#             */
/*   Updated: 2024/03/12 00:24:19 by selmandemir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pop_a_to_b(t_stack **a, t_stack **b, char c)
{
	set_index(a);
	set_index(b);
	set_target(*a, *b);
	set_cost(*a);
	find_cheapest(*a);
	prepare_to_push_a(a, b);
	push_a(b, a, c);
}

void	prepare_to_push_a(t_stack **a, t_stack **b)
{
	t_stack	*cheap_n;

	cheap_n = get_cheapest(*a);
	cheap_n -> cheapest = 0;
	go_top(a, b, cheap_n, cheap_n -> target);
}

void	go_top(t_stack **a, t_stack **b, t_stack *num_a, t_stack *num_b)
{
	while (num_a -> index > 0 && num_b -> index > 0)
	{
		rotate_both(a, b);
		num_a -> index -= 1;
		num_b -> index -= 1;
	}
	while (num_a -> index < 0 && num_b -> index < 0)
	{
		reverse_rotate_both(a, b);
		num_a -> index += 1;
		num_b -> index += 1;
	}
	while (num_a -> index < 0)
	{
		reverse_rotate_a(a, 'a', 1);
		num_a -> index += 1;
	}
	while (num_a -> index > 0)
	{
		rotate_a(a, 'a', 1);
		num_a -> index -= 1;
	}
	go_top_b(b, num_b);
}

void	go_top_b(t_stack **a, t_stack *num_a)
{
	set_index(a);
	while (num_a -> index < 0)
	{
		reverse_rotate_a(a, 'b', 1);
		num_a -> index += 1;
	}
	while (num_a -> index > 0)
	{
		rotate_a(a, 'b', 1);
		num_a -> index -= 1;
	}
}

void	go_top_a(t_stack **a, t_stack *num_a)
{
	set_index(a);
	while (num_a -> index < 0)
	{
		reverse_rotate_a(a, 'a', 1);
		num_a -> index += 1;
	}
	while (num_a -> index > 0)
	{
		rotate_a(a, 'a', 1);
		num_a -> index -= 1;
	}
}
