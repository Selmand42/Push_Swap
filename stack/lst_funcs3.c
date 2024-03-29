/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_funcs3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhademi <muhademi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:55:49 by muhademi          #+#    #+#             */
/*   Updated: 2024/03/29 18:55:44 by muhademi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_dup(t_stack **node)
{
	t_stack	*a;
	t_stack	*b;

	b = *node;
	while (b)
	{
		a = b -> next;
		while (a)
		{
			if (b -> number == a -> number)
				return (0);
			a = a -> next;
		}
		b = b -> next;
	}
	return (1);
}

int	check_sorted(t_stack **node)
{
	int		temp;
	t_stack	*temp_node;

	temp = INT32_MIN;
	temp_node = (*node);
	while (temp_node)
	{
		if ((temp_node)-> number < temp)
			return (0);
		temp = (temp_node)-> number;
		(temp_node) = (temp_node)-> next;
	}
	return (1);
}

t_stack	*ft_stack_new(int content)
{
	t_stack	*new;

	new = malloc(sizeof (t_stack));
	if (!new)
		ft_error();
	new->number = content;
	new->next = 0;
	return (new);
}

void	ft_add_back(t_stack **stack, t_stack *stack_new)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = stack_new;
	else
		(ft_lstlast(*stack))->next = stack_new;
}

void	ft_free(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		(*lst)->number = 0;
		free(*lst);
		*lst = tmp;
	}
}
