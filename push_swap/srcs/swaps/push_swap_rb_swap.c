/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rb_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:24:44 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/16 13:50:48 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	rb_swap_checker(t_stack *b_stack)
{
	int	len;

	if (b_stack == NULL)
		return (false);
	len = calc_stack_len(b_stack);
	if (len == 1)
		return (false);
	return (true);
}

static void	rb_swap_exec(t_stack *first,
	t_stack *first_previous, t_stack *last)
{
	set_stack_next(first_previous, NULL);
	set_stack_previous(first, NULL);
	set_stack_next(first, last);
	set_stack_previous(last, first);
}

void	rb_swap(t_swap_calc *swap_calc, t_stack **b_stack)
{
	t_stack	*last;
	t_stack	*first;
	t_stack	*first_previous;

	if (rb_swap_checker((*b_stack)) == false)
		return ;
	last = (*b_stack);
	while ((*b_stack)->next != NULL)
		(*b_stack) = (*b_stack)->next;
	first = (*b_stack);
	first_previous = (*b_stack)->previous;
	rb_swap_exec(first, first_previous, last);
	set_swap_calc_cmd(swap_calc, "rb\n");
	refresh_b_stack(swap_calc, b_stack);
}
