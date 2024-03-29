/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selmandemir <selmandemir@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:55:49 by muhademi          #+#    #+#             */
/*   Updated: 2024/03/12 00:23:45 by selmandemir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_lstsize(t_stack **lst)
{
	size_t	i;
	t_stack	*temp;

	if (!(*lst))
		return (0);
	i = 0;
	temp = (*lst);
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int	ft_stack_min(t_stack *a)
{
	int		i;

	i = a->number;
	while (a)
	{
		if (a->number < i)
			i = a->number;
		a = a->next;
	}
	return (i);
}

int	ft_stack_max(t_stack *a)
{
	int		i;

	i = a->number;
	while (a)
	{
		if (a->number > i)
			i = a->number;
		a = a->next;
	}
	return (i);
}

int	ft_find_index(t_stack *a, int number)
{
	int		i;

	i = 0;
	while (a->number != number)
	{
		i++;
		a = a->next;
	}
	a->index = 0;
	return (i);
}
