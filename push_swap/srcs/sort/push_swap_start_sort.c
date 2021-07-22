/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_start_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:24:24 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/20 19:51:34 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_median_high_number(t_swap_calc *swap_calc, t_stack *a_stack)
{
	while (a_stack != NULL)
	{
		if (get_stack_pos(a_stack) > get_swap_calc_high(swap_calc))
			set_swap_calc_high(swap_calc, get_stack_pos(a_stack));
		a_stack = get_stack_next(a_stack);
	}
	set_swap_calc_median(swap_calc, (get_swap_calc_high(swap_calc) / 2));
}

static bool	check_over_cases(t_swap_calc *swap_calc, t_stack **a_stack,
	t_stack **b_stack)
{
	int	len;

	len = get_swap_calc_stack_size(swap_calc);
	if (len == 1)
		return (true);
	if (over_check(a_stack, b_stack) == true)
		return (true);
	return (false);
}

void	start_sort(t_swap_calc *swap_calc, t_stack *a_stack)
{
	t_stack	*b_stack;

	b_stack = NULL;
	if (check_over_cases(swap_calc, &a_stack, &b_stack) == true)
		return ;
	get_median_high_number(swap_calc, a_stack);
	if (low_a_sort(swap_calc, &a_stack) == true)
		return ;
	if (low_sort(swap_calc) == true)
		initial_low_sort(swap_calc, &a_stack, &b_stack);
	else if (medium_sort(swap_calc) == true)
		initial_medium_sort(swap_calc, &a_stack, &b_stack);
	else if (long_sort(swap_calc) == true)
		initial_long_sort(swap_calc, &a_stack, &b_stack);
	backtracking_sort(swap_calc, &a_stack, &b_stack);
	set_low_start(swap_calc, &a_stack);
}
