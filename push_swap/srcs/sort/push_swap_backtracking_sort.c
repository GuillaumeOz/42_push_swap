/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_backtracking_sort.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 14:39:33 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/20 20:01:19 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reset_cmd(t_swap_calc *swap_calc)
{
	free(swap_calc->tmp_rr_cmd);
	swap_calc->tmp_rr_cmd = NULL;
	free(swap_calc->tmp_rrr_cmd);
	swap_calc->tmp_rrr_cmd = NULL;
	free(swap_calc->tmp_ra_rrb_cmd);
	swap_calc->tmp_ra_rrb_cmd = NULL;
	free(swap_calc->tmp_rb_rra_cmd);
	swap_calc->tmp_rb_rra_cmd = NULL;
}

static int	set_move(t_swap_calc *swap_calc)
{
	int	move;

	move = swap_calc->rrr_count;
	if (move > swap_calc->rr_count)
		move = swap_calc->rr_count;
	if (move > swap_calc->ra_rrb_count)
		move = swap_calc->ra_rrb_count;
	if (move > swap_calc->rb_rra_count)
		move = swap_calc->rb_rra_count;
	return (move);
}

static void	apply_rotation(t_swap_calc *swap_calc, t_stack **a_stack,
	t_stack **b_stack)
{
	int	move;

	move = set_move(swap_calc);
	if (move == swap_calc->rrr_count)
		apply_rrr_cmd(swap_calc, a_stack, b_stack);
	else if (move == swap_calc->ra_rrb_count)
		apply_ra_rrb_cmd(swap_calc, a_stack, b_stack);
	else if (move == swap_calc->rr_count)
		apply_rr_cmd(swap_calc, a_stack, b_stack);
	else if (move == swap_calc->rb_rra_count)
		apply_rb_rra_cmd(swap_calc, a_stack, b_stack);
}

void	backtracking_sort(t_swap_calc *swap_calc, t_stack **a_stack,
	t_stack **b_stack)
{
	while ((*b_stack) != NULL)
	{	
		refresh_a_stack(swap_calc, a_stack);
		refresh_b_stack(swap_calc, b_stack);
		load_rr_way(swap_calc, a_stack, b_stack);
		load_rrr_way(swap_calc, a_stack, b_stack);
		load_ra_rrb_way(swap_calc, a_stack, b_stack);
		load_rb_rra_way(swap_calc, a_stack, b_stack);
		swap_calc->rr_count = count_rr_cmd(swap_calc->tmp_rr_cmd);
		swap_calc->rrr_count = count_rrr_cmd(swap_calc->tmp_rrr_cmd);
		swap_calc->ra_rrb_count = count_ra_rrb_cmd(swap_calc->tmp_ra_rrb_cmd);
		swap_calc->rb_rra_count = count_rb_rra_cmd(swap_calc->tmp_rb_rra_cmd);
		apply_rotation(swap_calc, a_stack, b_stack);
		reset_cmd(swap_calc);
	}
}
