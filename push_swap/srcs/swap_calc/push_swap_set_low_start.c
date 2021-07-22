/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_set_low_start.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 18:08:02 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/16 14:36:39 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_from_ra(t_swap_calc *swap_calc, t_stack *a_tmp, int *ra)
{
	t_stack	*tmp;

	tmp = get_stack_first(a_tmp);
	while (get_stack_pos(tmp) != get_swap_calc_low(swap_calc))
	{
		(*ra)++;
		tmp = get_stack_previous(tmp);
	}
}

void	calc_from_rra(t_swap_calc *swap_calc, t_stack *a_tmp, int *rra)
{
	t_stack	*tmp;

	tmp = get_stack_last(a_tmp);
	while (get_stack_pos(tmp) != get_swap_calc_low(swap_calc))
	{
		(*rra)++;
		tmp = get_stack_next(tmp);
	}
}

static void	set_rra(t_swap_calc *swap_calc, t_stack **a_stack,
	int rra)
{
	while (rra > 0)
	{
		rra_swap(swap_calc, a_stack);
		rra--;
	}	
}

static void	set_ra(t_swap_calc *swap_calc, t_stack **a_stack,
	int ra)
{
	while (ra > 0)
	{
		ra_swap(swap_calc, a_stack);
		ra--;
	}
}

void	set_low_start(t_swap_calc *swap_calc, t_stack **a_stack)
{
	t_stack	*tmp;
	int		ra;
	int		rra;

	ra = 0;
	rra = 1;
	tmp = get_stack_first((*a_stack));
	calc_from_ra(swap_calc, tmp, &ra);
	calc_from_rra(swap_calc, tmp, &rra);
	if (ra < rra)
		set_ra(swap_calc, a_stack, ra);
	else
		set_rra(swap_calc, a_stack, rra);
	refresh_a_stack(swap_calc, a_stack);
}
