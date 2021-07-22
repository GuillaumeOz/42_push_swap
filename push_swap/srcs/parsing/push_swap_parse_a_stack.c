/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parse_a_stack.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:09:50 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/16 15:31:19 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_first_node(t_stack *a_stack)
{
	set_stack_next(a_stack, NULL);
	set_stack_previous(a_stack, NULL);
}

static void	set_nodes(t_stack *a_stack, t_stack *tmp)
{
	set_stack_previous(tmp, a_stack);
	set_stack_next(a_stack, tmp);
	set_stack_previous(a_stack, NULL);
}

static t_stack	*parse_a_stack_elements(char **tab, size_t len)
{
	t_stack	*a_stack;
	t_stack	*tmp;
	size_t	i;
	int		number;
	int		set_number;

	i = 0;
	a_stack = NULL;
	set_number = len - 1;
	while (i < len)
	{
		number = ft_atoi(tab[set_number]);
		tmp = a_stack;
		a_stack = malloc_stack(number);
		if (tmp == NULL)
			set_first_node(a_stack);
		else
			set_nodes(a_stack, tmp);
		i++;
		set_number--;
	}
	return (a_stack);
}

static void	check_double_int_value(t_stack	*a_stack)
{
	bool	double_number;
	t_stack	*i;
	t_stack	*j;

	i = a_stack;
	while (i != NULL)
	{
		j = a_stack;
		double_number = false;
		while (j != NULL)
		{
			if ((get_stack_number(i) == get_stack_number(j))
				&& double_number == false)
				double_number = true;
			else if ((get_stack_number(i) == get_stack_number(j))
				&& double_number == true)
				push_swap_error("Error\n");
			j = get_stack_next(j);
		}
		i = get_stack_next(i);
	}
}

t_stack	*parse_a_stack(char **tab)
{
	t_stack	*a_stack;
	size_t	len;

	len = 0;
	while (tab[len] != NULL)
		len++;
	a_stack = parse_a_stack_elements(tab, len);
	check_double_int_value(a_stack);
	set_elements_pos(a_stack);
	return (a_stack);
}
