/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_t_swap_calc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:30:47 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/20 15:54:36 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_swap_calc	*malloc_swap_calc(int stack_size)
{
	t_swap_calc	*swap_calc;

	swap_calc = (t_swap_calc *)malloc(sizeof(t_swap_calc));
	if (swap_calc == NULL)
		checker_error("Error\n");
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
	return (swap_calc);
}

void	destroy_swap_calc(t_swap_calc swap_calc)
{
	swap_calc.stack_size = 0;
	swap_calc.a_stack_size = 0;
	swap_calc.a_display_swap = false;
	swap_calc.b_stack_size = 0;
	swap_calc.b_display_swap = false;
	free(swap_calc.cmd);
}

void	free_swap_calc(t_swap_calc *swap_calc)
{
	destroy_swap_calc(*swap_calc);
	free(swap_calc);
}
