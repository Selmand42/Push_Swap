/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selmandemir <selmandemir@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:55:49 by muhademi          #+#    #+#             */
/*   Updated: 2024/03/12 00:24:10 by selmandemir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(void)
{
	ft_printf("Error\n");
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = fill_stack_a(argc, argv);
	if (!a || !check_dup(&a))
		return (ft_error());
	else if (!check_sorted(&a))
		sort(&a);
	ft_free(&a);
	return (0);
}
