/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_t_swap_calc_setter.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:37:10 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/20 15:41:49 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	set_swap_calc_stack_size(t_swap_calc *swap_calc, int value)
{
	swap_calc->stack_size = value;
}

void	set_swap_calc_high(t_swap_calc *swap_calc, int value)
{
	swap_calc->high = value;
}

void	set_swap_calc_median(t_swap_calc *swap_calc, int value)
{
	swap_calc->median = value;
}

void	set_swap_calc_cmd(t_swap_calc *swap_calc, char *cmd)
{
	if (get_swap_calc_a_display_swap(swap_calc) == true)
		swap_calc->cmd = ft_strappend(swap_calc->cmd, cmd, true, false);
}
