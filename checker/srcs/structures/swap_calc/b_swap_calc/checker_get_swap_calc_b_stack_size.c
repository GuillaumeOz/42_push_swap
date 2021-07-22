/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_get_swap_calc_b_stack_size.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:39:33 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/16 13:10:35 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	get_swap_calc_b_stack_size(t_swap_calc *swap_calc)
{
	return (swap_calc->b_stack_size);
}

bool	get_swap_calc_b_display_swap(t_swap_calc *swap_calc)
{
	return (swap_calc->b_display_swap);
}
