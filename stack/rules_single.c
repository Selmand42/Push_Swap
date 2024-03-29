/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_single.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhademi <muhademi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:55:49 by muhademi          #+#    #+#             */
/*   Updated: 2024/03/27 12:23:46 by muhademi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_stack **a, char c, int cond)
{
	t_stack	*temp;

	if (!(*a) || !(*a)-> next)
		return ;
	temp = (*a);
	(*a) = (*a)-> next;
	temp -> next = (*a)-> next;
	(*a)-> next = temp;
	if (cond)
		ft_printf("s%c\n", c);
}

void	push_a(t_stack **a, t_stack **b, char c)
{
	t_stack	*temp;

	if (!(*b))
		return ;
	temp = (*a);
	(*a) = (*b);
	(*b) = (*b)-> next;
	(*a)-> next = temp;
	ft_printf("p%c\n", c);
}

void	rotate_a(t_stack **a, char c, int cond)
{
	t_stack	*temp;

	if (!(*a) || !((*a)-> next))
		return ;
	temp = (*a);
	(*a) = ft_lstlast(*a);
	(*a)-> next = temp;
	(*a) = temp-> next;
	temp -> next = NULL;
	if (cond)
		ft_printf("r%c\n", c);
}

void	reverse_rotate_a(t_stack **a, char c, int cond)
{
	t_stack	*tmp;
	int		i;

	if (!*a || !(*a)->next)
		return ;
	i = 0;
	tmp = *a;
	while ((*a)->next)
	{
		*a = (*a)->next;
		i++;
	}
	(*a)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (cond)
		ft_printf("rr%c\n", c);
}
