/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_a_to_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selmandemir <selmandemir@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:55:49 by muhademi          #+#    #+#             */
/*   Updated: 2024/03/12 00:24:15 by selmandemir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack **a)
{
	int		len;
	int		i;
	t_stack	*temp;

	i = 0;
	len = ft_lstsize(a);
	temp = (*a);
	while (temp)
	{
		temp -> index = ft_min(i, len - i);
		if (temp -> index == len - i)
			temp -> index = temp -> index * (-1);
		i += 1;
		temp = temp -> next;
	}
}

void	set_target(t_stack *a, t_stack *b)
{
	t_stack	*temp_b;
	t_stack	*target;
	int		temp_best;

	while (a)
	{
		temp_best = INT_MIN;
		temp_b = b;
		while (temp_b)
		{
			if (temp_b->number < a->number
				&& temp_b->number > temp_best)
			{
				temp_best = temp_b->number;
				target = temp_b;
			}
			temp_b = temp_b->next;
		}
		if (temp_best == INT_MIN)
			a -> target = find_max_node(b);
		else
			a -> target = target;
		a = a -> next;
	}
}

void	find_cheapest(t_stack *a)
{
	int		cheapest_value;
	t_stack	*cheapest_node;

	if (!a)
		return ;
	cheapest_value = INT_MAX;
	while (a)
	{
		if (a->cost < cheapest_value)
		{
			cheapest_value = a->cost;
			cheapest_node = a;
		}
		a = a->next;
	}
	cheapest_node->cheapest = 1;
}

t_stack	*get_cheapest(t_stack *a)
{
	while (a -> cheapest == 0)
		a = a -> next;
	return (a);
}

void	set_cost(t_stack *a)
{
	if (!a)
		return ;
	while (a)
	{
		a -> cost = ft_abs(a -> index) + ft_abs(a -> target -> index);
		a = a->next;
	}
}
