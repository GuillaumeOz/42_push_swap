/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_types.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:35:19 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/16 12:28:23 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	low_sort(t_swap_calc *swap_calc)
{
	if (get_swap_calc_a_stack_size(swap_calc) <= 6)
		return (true);
	return (false);
}

bool	medium_sort(t_swap_calc *swap_calc)
{
	if (get_swap_calc_a_stack_size(swap_calc) <= 200)
		return (true);
	return (false);
}

bool	long_sort(t_swap_calc *swap_calc)
{
	if (get_swap_calc_a_stack_size(swap_calc) > 200)
		return (true);
	return (false);
}
