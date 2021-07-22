/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_over_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:00:49 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/16 13:45:13 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	over_check(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*tmp;

	if ((*b_stack) != NULL)
		return (false);
	tmp = get_stack_first((*a_stack));
	while (tmp->previous != NULL)
	{
		if (get_stack_pos(tmp) > get_stack_pos(tmp->previous))
			return (false);
		tmp = get_stack_previous(tmp);
	}
	return (true);
}
