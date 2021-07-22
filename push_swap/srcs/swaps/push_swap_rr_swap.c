/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rr_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:24:47 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/16 14:00:35 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_swap(t_swap_calc *swap_calc, t_stack **a_stack, t_stack **b_stack)
{
	set_swap_calc_a_display_swap(swap_calc, false);
	ra_swap(swap_calc, a_stack);
	set_swap_calc_b_display_swap(swap_calc, false);
	rb_swap(swap_calc, b_stack);
	set_swap_calc_a_display_swap(swap_calc, true);
	set_swap_calc_b_display_swap(swap_calc, true);
	if (swap_calc->rr_tmp == true)
		swap_calc->tmp_rr_cmd = ft_strappend(swap_calc->tmp_rr_cmd,
				"rr\n", true, false);
	else
		swap_calc->cmd = ft_strappend(swap_calc->cmd, "rr\n", true, false);
}
