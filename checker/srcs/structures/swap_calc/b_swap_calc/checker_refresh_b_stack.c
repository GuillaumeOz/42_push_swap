/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_refresh_b_stack.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:06:02 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/16 13:10:58 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	refresh_b_stack(t_swap_calc *swap_calc, t_stack **b_stack)
{
	int	len;

	len = calc_stack_len((*b_stack));
	set_swap_calc_b_stack_size(swap_calc, len);
	if (len == 0)
	{
		(*b_stack) = NULL;
		return ;
	}
	while ((*b_stack)->previous != NULL)
		(*b_stack) = (*b_stack)->previous;
}
