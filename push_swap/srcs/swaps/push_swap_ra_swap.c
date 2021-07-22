/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ra_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:24:41 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/16 14:01:21 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	ra_swap_checker(t_stack *a_stack)
{
	int	len;

	if (a_stack == NULL)
		return (false);
	len = calc_stack_len(a_stack);
	if (len == 1)
		return (false);
	return (true);
}

static void	ra_swap_exec(t_stack *first,
	t_stack *first_previous, t_stack *last)
{
	set_stack_next(first_previous, NULL);
	set_stack_previous(first, NULL);
	set_stack_next(first, last);
	set_stack_previous(last, first);
}

void	ra_swap(t_swap_calc *swap_calc, t_stack **a_stack)
{
	t_stack	*last;
	t_stack	*first;
	t_stack	*first_previous;

	if (ra_swap_checker((*a_stack)) == false)
		return ;
	last = (*a_stack);
	while ((*a_stack)->next != NULL)
		(*a_stack) = (*a_stack)->next;
	first = (*a_stack);
	first_previous = (*a_stack)->previous;
	ra_swap_exec(first, first_previous, last);
	set_swap_calc_cmd(swap_calc, "ra\n");
	refresh_a_stack(swap_calc, a_stack);
}
