/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rrb_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:25:07 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/16 13:09:11 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static bool	rrb_swap_checker(t_stack *b_stack)
{
	int	len;

	if (b_stack == NULL)
		return (false);
	len = calc_stack_len(b_stack);
	if (len == 1)
		return (false);
	return (true);
}

static void	rrb_swap_exec(t_stack *first,
	t_stack *last, t_stack *last_next)
{
	set_stack_previous(last_next, NULL);
	set_stack_previous(last, first);
	set_stack_next(last, NULL);
	set_stack_next(first, last);
}

void	rrb_swap(t_swap_calc *swap_calc, t_stack **b_stack)
{
	t_stack	*last;
	t_stack	*last_next;
	t_stack	*first;

	if (rrb_swap_checker((*b_stack)) == false)
		return ;
	last = (*b_stack);
	last_next = (*b_stack)->next;
	while ((*b_stack)->next != NULL)
		(*b_stack) = (*b_stack)->next;
	first = (*b_stack);
	rrb_swap_exec(first, last, last_next);
	set_swap_calc_cmd(swap_calc, "rrb\n");
	refresh_b_stack(swap_calc, b_stack);
}
