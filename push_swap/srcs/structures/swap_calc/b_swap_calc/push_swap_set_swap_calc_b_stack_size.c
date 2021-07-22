/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_set_swap_calc_b_stack_size.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:39:09 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/16 13:59:50 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_swap_calc_b_stack_size(t_swap_calc *swap_calc, int value)
{
	swap_calc->b_stack_size = value;
}

void	set_swap_calc_b_display_swap(t_swap_calc *swap_calc, bool value)
{
	swap_calc->b_display_swap = value;
}
