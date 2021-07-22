/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ss_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:25:33 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/15 18:28:32 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ss_swap(t_swap_calc *swap_calc, t_stack **a_stack, t_stack **b_stack)
{
	set_swap_calc_a_display_swap(swap_calc, false);
	sa_swap(swap_calc, a_stack);
	set_swap_calc_b_display_swap(swap_calc, false);
	sb_swap(swap_calc, b_stack);
	set_swap_calc_a_display_swap(swap_calc, true);
	set_swap_calc_b_display_swap(swap_calc, true);
	swap_calc->cmd = ft_strappend(swap_calc->cmd, "ss\n", true, false);
}
