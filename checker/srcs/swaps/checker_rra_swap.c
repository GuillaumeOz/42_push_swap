/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rra_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:25:04 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/16 13:07:57 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static bool	rra_swap_checker(t_stack *a_stack)
{
	int	len;

	if (a_stack == NULL)
		return (false);
	len = calc_stack_len(a_stack);
	if (len == 1)
		return (false);
	return (true);
}

static void	rra_swap_exec(t_stack *first,
	t_stack *last, t_stack *last_next)
{
	set_stack_previous(last_next, NULL);
	set_stack_previous(last, first);
	set_stack_next(last, NULL);
	set_stack_next(first, last);
}

void	rra_swap(t_swap_calc *swap_calc, t_stack **a_stack)
{
	t_stack	*last;
	t_stack	*last_next;
	t_stack	*first;

	if (rra_swap_checker((*a_stack)) == false)
		return ;
	last = (*a_stack);
	last_next = (*a_stack)->next;
	while ((*a_stack)->next != NULL)
		(*a_stack) = (*a_stack)->next;
	first = (*a_stack);
	rra_swap_exec(first, last, last_next);
	set_swap_calc_cmd(swap_calc, "rra\n");
	refresh_a_stack(swap_calc, a_stack);
}
