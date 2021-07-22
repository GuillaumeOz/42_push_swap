/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_low_b_sort_switch_cases.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:38:52 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/16 14:13:20 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	sb_swap_case(t_swap_calc *swap_calc, t_stack **b_stack)
{
	t_stack	*previous;
	t_stack	*middle;
	t_stack	*next;

	next = (*b_stack);
	middle = get_stack_next(*b_stack);
	previous = get_stack_next(middle);
	if (get_stack_pos(middle) < get_stack_pos(previous)
		&& get_stack_pos(middle) < get_stack_pos(next)
		&& get_stack_pos(previous) < get_stack_pos(next))
	{
		sb_swap(swap_calc, b_stack);
		return (true);
	}
	return (false);
}

bool	rb_swap_case(t_swap_calc *swap_calc, t_stack **b_stack)
{
	t_stack	*previous;
	t_stack	*middle;
	t_stack	*next;

	previous = (*b_stack);
	middle = get_stack_next(*b_stack);
	next = get_stack_next(middle);
	if (get_stack_pos(middle) < get_stack_pos(previous)
		&& get_stack_pos(middle) < get_stack_pos(next)
		&& get_stack_pos(previous) < get_stack_pos(next))
	{
		rb_swap(swap_calc, b_stack);
		return (true);
	}
	return (false);
}

bool	rrb_swap_case(t_swap_calc *swap_calc, t_stack **b_stack)
{
	t_stack	*previous;
	t_stack	*middle;
	t_stack	*next;

	previous = (*b_stack);
	middle = get_stack_next(*b_stack);
	next = get_stack_next(middle);
	if (get_stack_pos(middle) > get_stack_pos(previous)
		&& get_stack_pos(middle) > get_stack_pos(next)
		&& get_stack_pos(previous) < get_stack_pos(next))
	{
		rrb_swap(swap_calc, b_stack);
		return (true);
	}
	return (false);
}

bool	sb_rrb_swap_case(t_swap_calc *swap_calc, t_stack **b_stack)
{
	t_stack	*previous;
	t_stack	*middle;
	t_stack	*next;

	previous = (*b_stack);
	middle = get_stack_next(*b_stack);
	next = get_stack_next(middle);
	if (get_stack_pos(middle) > get_stack_pos(previous)
		&& get_stack_pos(middle) < get_stack_pos(next)
		&& get_stack_pos(previous) < get_stack_pos(next))
	{
		sb_swap(swap_calc, b_stack);
		rrb_swap(swap_calc, b_stack);
		return (true);
	}
	return (false);
}

bool	sb_rb_swap_case(t_swap_calc *swap_calc, t_stack **b_stack)
{
	t_stack	*previous;
	t_stack	*middle;
	t_stack	*next;

	previous = (*b_stack);
	middle = get_stack_next(*b_stack);
	next = get_stack_next(middle);
	if (get_stack_pos(middle) > get_stack_pos(previous)
		&& get_stack_pos(middle) > get_stack_pos(next)
		&& get_stack_pos(previous) > get_stack_pos(next))
	{
		sb_swap(swap_calc, b_stack);
		rb_swap(swap_calc, b_stack);
		return (true);
	}
	return (false);
}
