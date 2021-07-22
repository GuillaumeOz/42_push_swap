/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_medium_sort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 10:31:07 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/16 15:10:14 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	low_high_sort(t_swap_calc *swap_calc, t_stack **a_stack,
	t_stack **b_stack)
{
	t_stack	*tmp;
	int		len;
	int		i;

	i = 0;
	len = get_swap_calc_stack_size(swap_calc);
	while (i < len)
	{
		tmp = get_stack_first((*a_stack));
		if (get_stack_pos(tmp) == get_swap_calc_low(swap_calc))
			ra_swap(swap_calc, a_stack);
		else if (get_stack_pos(tmp) == get_swap_calc_median(swap_calc))
			ra_swap(swap_calc, a_stack);
		else if (get_stack_pos(tmp) == get_swap_calc_high(swap_calc))
			ra_swap(swap_calc, a_stack);
		else if (get_stack_pos(tmp) < get_swap_calc_median(swap_calc))
		{
			pb_swap(swap_calc, b_stack, (*a_stack));
			rb_swap(swap_calc, b_stack);
		}
		else if (get_stack_pos(tmp) > get_swap_calc_median(swap_calc))
			pb_swap(swap_calc, b_stack, (*a_stack));
		i++;
	}
}

void	initial_medium_sort(t_swap_calc *swap_calc, t_stack **a_stack,
	t_stack **b_stack)
{
	low_high_sort(swap_calc, a_stack, b_stack);
	refresh_a_stack(swap_calc, a_stack);
	low_a_sort(swap_calc, a_stack);
	refresh_b_stack(swap_calc, b_stack);
}
