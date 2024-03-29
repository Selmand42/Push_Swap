/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_first_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhademi <muhademi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:55:49 by muhademi          #+#    #+#             */
/*   Updated: 2024/03/29 20:01:58 by muhademi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*fill_stack_a(int argc, char **argv)
{
	t_stack	*numbers;

	if (argc == 1)
		return (0);
	if (argc == 2)
		numbers = str_to_stack(argv[1]);
	else
		numbers = arr_to_stack(argc - 1, &argv[1]);
	return (numbers);
}

void	fill_stack(t_stack **node, char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
	{
		ft_add_back(node, ft_stack_new(ft_atoi(numbers[i])));
		i++;
	}
}

t_stack	*str_to_stack(char *str)
{
	char	**numbers;
	t_stack	*node;
	int		i;

	numbers = ft_split(str, ' ');
	i = 0;
	while (numbers[i])
	{
		if (!check_string(numbers[i]))
			return (0);
		i++;
	}
	node = NULL;
	fill_stack(&node, numbers);
	i = -1;
	while (numbers[++i])
		free(numbers[i]);
	free(numbers);
	return (node);
}

int	check_string(char *str)
{
	int					i;
	unsigned long int	num;
	int					ten;

	num = 0;
	ten = 1;
	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		if (str[i] == '-' && (!str[i + 1] || !ft_isdigit(str[i + 1])))
			return (0);
		else if (!ft_isdigit(str[i]) && str[i] != '-')
			return (0);
		if (str[i] != '-')
		{
			num += ten * (str[i] - '0');
			ten *= 10;
		}
		i--;
	}
	if ((str[0] == '-' && num > 2147483648)
		|| (str[0] != '-' && num > 2147483647))
		return (0);
	return (1);
}

t_stack	*arr_to_stack(int count, char **arr)
{
	t_stack	*node;
	int		i;

	i = 0;
	while (i < count)
	{
		if (!ft_isnumber(arr[i]) || !check_string(arr[i]))
			return (0);
		i++;
	}
	node = NULL;
	fill_stack(&node, arr);
	return (node);
}
