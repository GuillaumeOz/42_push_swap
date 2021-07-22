/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_set_swap_calc_a_stack_size.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:36:40 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/16 14:01:28 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_swap_calc_a_stack_size(t_swap_calc *swap_calc, int value)
{
	swap_calc->a_stack_size = value;
}

void	set_swap_calc_a_display_swap(t_swap_calc *swap_calc, bool value)
{
	swap_calc->a_display_swap = value;
}
