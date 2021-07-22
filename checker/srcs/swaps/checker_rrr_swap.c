/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rrr_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:25:10 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/19 15:28:23 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rrr_swap(t_swap_calc *swap_calc, t_stack **a_stack, t_stack **b_stack)
{
	set_swap_calc_a_display_swap(swap_calc, false);
	rra_swap(swap_calc, a_stack);
	set_swap_calc_b_display_swap(swap_calc, false);
	rrb_swap(swap_calc, b_stack);
	set_swap_calc_a_display_swap(swap_calc, true);
	set_swap_calc_b_display_swap(swap_calc, true);
	if (swap_calc->rrr_tmp == true)
		swap_calc->tmp_rrr_cmd = ft_strappend(swap_calc->tmp_rrr_cmd,
				"rrr\n", true, false);
	else
		swap_calc->cmd = ft_strappend(swap_calc->cmd, "rrr\n", true, false);
}
