/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_t_swap_calc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:30:47 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/20 18:10:14 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swap_calc	*malloc_swap_calc(int stack_size)
{
	t_swap_calc	*swap_calc;

	swap_calc = (t_swap_calc *)malloc(sizeof(t_swap_calc));
	if (swap_calc == NULL)
		push_swap_error("Error\n");
	*swap_calc = create_swap_calc(stack_size);
	return (swap_calc);
}

t_swap_calc	create_swap_calc(int stack_size)
{
	t_swap_calc	swap_calc;

	swap_calc.stack_size = stack_size;
	swap_calc.a_stack_size = stack_size;
	swap_calc.a_display_swap = true;
	swap_calc.b_stack_size = 0;
	swap_calc.b_display_swap = true;
	swap_calc.cmd = NULL;
	swap_calc.tmp_pos = 0;
	swap_calc.chain_pos = 0;
	swap_calc.low = 0;
	swap_calc.median = 0;
	swap_calc.high = 0;
	swap_calc.rr_tmp = false;
	swap_calc.rrr_tmp = false;
	swap_calc.rr_count = 0;
	swap_calc.rrr_count = 0;
	swap_calc.ra_rrb_count = 0;
	swap_calc.rb_rra_count = 0;
	swap_calc.tmp_rr_cmd = NULL;
	swap_calc.tmp_rrr_cmd = NULL;
	swap_calc.tmp_ra_rrb_cmd = NULL;
	swap_calc.tmp_rb_rra_cmd = NULL;
	return (swap_calc);
}

void	destroy_swap_calc(t_swap_calc swap_calc)
{
	free(swap_calc.cmd);
	free(swap_calc.tmp_rr_cmd);
	free(swap_calc.tmp_rrr_cmd);
	free(swap_calc.tmp_ra_rrb_cmd);
	free(swap_calc.tmp_rb_rra_cmd);
}

void	free_swap_calc(t_swap_calc *swap_calc)
{
	destroy_swap_calc(*swap_calc);
	free(swap_calc);
}
