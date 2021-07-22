/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_low_a_sort_switch_cases.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:38:52 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/16 14:14:09 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	sa_swap_case(t_swap_calc *swap_calc, t_stack **a_stack)
{
	t_stack	*previous;
	t_stack	*middle;
	t_stack	*next;

	next = (*a_stack);
	middle = get_stack_next(*a_stack);
	previous = get_stack_next(middle);
	if (get_stack_pos(middle) < get_stack_pos(previous)
		&& get_stack_pos(middle) < get_stack_pos(next)
		&& get_stack_pos(previous) < get_stack_pos(next))
	{
		sa_swap(swap_calc, a_stack);
		return (true);
	}
	return (false);
}

bool	ra_swap_case(t_swap_calc *swap_calc, t_stack **a_stack)
{
	t_stack	*previous;
	t_stack	*middle;
	t_stack	*next;

	previous = (*a_stack);
	middle = get_stack_next(*a_stack);
	next = get_stack_next(middle);
	if (get_stack_pos(middle) < get_stack_pos(previous)
		&& get_stack_pos(middle) < get_stack_pos(next)
		&& get_stack_pos(previous) < get_stack_pos(next))
	{
		ra_swap(swap_calc, a_stack);
		return (true);
	}
	return (false);
}

bool	rra_swap_case(t_swap_calc *swap_calc, t_stack **a_stack)
{
	t_stack	*previous;
	t_stack	*middle;
	t_stack	*next;

	previous = (*a_stack);
	middle = get_stack_next(*a_stack);
	next = get_stack_next(middle);
	if (get_stack_pos(middle) > get_stack_pos(previous)
		&& get_stack_pos(middle) > get_stack_pos(next)
		&& get_stack_pos(previous) < get_stack_pos(next))
	{
		rra_swap(swap_calc, a_stack);
		return (true);
	}
	return (false);
}

bool	sa_rra_swap_case(t_swap_calc *swap_calc, t_stack **a_stack)
{
	t_stack	*previous;
	t_stack	*middle;
	t_stack	*next;

	previous = (*a_stack);
	middle = get_stack_next(*a_stack);
	next = get_stack_next(middle);
	if (get_stack_pos(middle) > get_stack_pos(previous)
		&& get_stack_pos(middle) < get_stack_pos(next)
		&& get_stack_pos(previous) < get_stack_pos(next))
	{
		sa_swap(swap_calc, a_stack);
		rra_swap(swap_calc, a_stack);
		return (true);
	}
	return (false);
}

bool	sa_ra_swap_case(t_swap_calc *swap_calc, t_stack **a_stack)
{
	t_stack	*previous;
	t_stack	*middle;
	t_stack	*next;

	previous = (*a_stack);
	middle = get_stack_next(*a_stack);
	next = get_stack_next(middle);
	if (get_stack_pos(middle) > get_stack_pos(previous)
		&& get_stack_pos(middle) > get_stack_pos(next)
		&& get_stack_pos(previous) > get_stack_pos(next))
	{
		sa_swap(swap_calc, a_stack);
		ra_swap(swap_calc, a_stack);
		return (true);
	}
	return (false);
}
