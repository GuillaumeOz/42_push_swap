/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_simple_sort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:58:28 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/15 14:54:34 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	very_low_a_sort(t_swap_calc *swap_calc, t_stack **a_stack)
{
	if (sa_swap_case(swap_calc, a_stack) == true)
		return ;
	else if (ra_swap_case(swap_calc, a_stack) == true)
		return ;
	else if (rra_swap_case(swap_calc, a_stack) == true)
		return ;
	else if (sa_rra_swap_case(swap_calc, a_stack) == true)
		return ;
	else if (sa_ra_swap_case(swap_calc, a_stack) == true)
		return ;
}

static void	very_low_b_sort(t_swap_calc *swap_calc, t_stack **b_stack)
{
	if (sb_swap_case(swap_calc, b_stack) == true)
		return ;
	else if (rb_swap_case(swap_calc, b_stack) == true)
		return ;
	else if (rrb_swap_case(swap_calc, b_stack) == true)
		return ;
	else if (sb_rrb_swap_case(swap_calc, b_stack) == true)
		return ;
	else if (sb_rb_swap_case(swap_calc, b_stack) == true)
		return ;
}

bool	low_a_sort(t_swap_calc *swap_calc, t_stack **a_stack)
{
	if (get_swap_calc_a_stack_size(swap_calc) <= 3)
	{
		if (get_swap_calc_a_stack_size(swap_calc) == 2)
			sa_swap(swap_calc, a_stack);
		else if (get_swap_calc_a_stack_size(swap_calc) == 3)
			very_low_a_sort(swap_calc, a_stack);
		return (true);
	}
	return (false);
}

bool	low_b_sort(t_swap_calc *swap_calc, t_stack **b_stack)
{
	if (get_swap_calc_b_stack_size(swap_calc) <= 3)
	{
		if (get_swap_calc_b_stack_size(swap_calc) == 2)
			sb_swap(swap_calc, b_stack);
		else if (get_swap_calc_b_stack_size(swap_calc) == 3)
			very_low_b_sort(swap_calc, b_stack);
		return (true);
	}
	return (false);
}
