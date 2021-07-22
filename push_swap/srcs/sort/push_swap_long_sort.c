/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_long_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 10:31:07 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/16 14:11:47 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	under_median(t_swap_calc *swap_calc, t_stack **a_stack,
	t_stack **b_stack, t_stack *tmp)
{
	if (get_stack_pos(tmp) < (get_swap_calc_median(swap_calc) / 2))
		pb_swap(swap_calc, b_stack, (*a_stack));
	else
	{
		pb_swap(swap_calc, b_stack, (*a_stack));
		rb_swap(swap_calc, b_stack);
	}
}

static void	lower_sort(t_swap_calc *swap_calc, t_stack **a_stack,
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
		if (get_stack_pos(tmp) == get_swap_calc_low(swap_calc)
			|| get_stack_pos(tmp) == get_swap_calc_median(swap_calc)
			|| get_stack_pos(tmp) == get_swap_calc_high(swap_calc))
			ra_swap(swap_calc, a_stack);
		else if (get_stack_pos(tmp) < get_swap_calc_median(swap_calc))
			under_median(swap_calc, a_stack, b_stack, tmp);
		else if (get_stack_pos(tmp) > get_swap_calc_median(swap_calc))
			ra_swap(swap_calc, a_stack);
		i++;
	}
	swap_calc->tmp_pos = get_stack_pos(get_stack_first((*b_stack)));
}

static void	above_median(t_swap_calc *swap_calc, t_stack **a_stack,
	t_stack **b_stack, t_stack *tmp)
{
	int	quart;

	quart = (get_swap_calc_median(swap_calc) / 2);
	if (get_stack_pos(tmp) > (get_swap_calc_median(swap_calc) / 2) + quart)
		pb_swap(swap_calc, b_stack, (*a_stack));
	else
	{
		pb_swap(swap_calc, b_stack, (*a_stack));
		rb_swap(swap_calc, b_stack);
	}
}

static void	higher_sort(t_swap_calc *swap_calc, t_stack **a_stack,
	t_stack **b_stack)
{
	t_stack	*tmp;
	int		len;
	int		i;

	i = 0;
	len = get_swap_calc_a_stack_size(swap_calc);
	while (i < len)
	{
		tmp = get_stack_first((*a_stack));
		if (get_stack_pos(tmp) == get_swap_calc_low(swap_calc)
			|| get_stack_pos(tmp) == get_swap_calc_median(swap_calc)
			|| get_stack_pos(tmp) == get_swap_calc_high(swap_calc))
			ra_swap(swap_calc, a_stack);
		else if (get_stack_pos(tmp) > get_swap_calc_median(swap_calc))
			above_median(swap_calc, a_stack, b_stack, tmp);
		i++;
	}
}

void	initial_long_sort(t_swap_calc *swap_calc, t_stack **a_stack,
	t_stack **b_stack)
{
	lower_sort(swap_calc, a_stack, b_stack);
	refresh_a_stack(swap_calc, a_stack);
	higher_sort(swap_calc, a_stack, b_stack);
	refresh_a_stack(swap_calc, a_stack);
	low_a_sort(swap_calc, a_stack);
}
