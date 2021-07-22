/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_refresh_a_stack.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:15:06 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/16 13:10:03 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	refresh_a_stack(t_swap_calc *swap_calc, t_stack **a_stack)
{
	int	len;

	len = calc_stack_len((*a_stack));
	set_swap_calc_a_stack_size(swap_calc, len);
	while ((*a_stack)->previous != NULL)
		(*a_stack) = (*a_stack)->previous;
}
