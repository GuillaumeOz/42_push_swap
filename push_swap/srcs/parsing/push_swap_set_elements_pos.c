/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_set_elements_pos.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 18:32:36 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/16 14:16:15 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_elements_pos(t_stack *a_stack)
{
	t_stack	*i;
	t_stack	*j;
	int		position;

	i = a_stack;
	while (i != NULL)
	{
		position = 0;
		j = a_stack;
		while (j != NULL)
		{
			if (get_stack_number(i) != get_stack_number(j)
				&& get_stack_number(i) > get_stack_number(j))
				position++;
			j = get_stack_next(j);
		}
		set_stack_pos(i, position);
		i = get_stack_next(i);
	}
}
