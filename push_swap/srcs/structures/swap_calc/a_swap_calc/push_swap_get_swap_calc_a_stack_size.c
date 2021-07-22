/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_get_swap_calc_a_stack_size.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:36:16 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/16 14:01:39 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_swap_calc_a_stack_size(t_swap_calc *swap_calc)
{
	return (swap_calc->a_stack_size);
}

bool	get_swap_calc_a_display_swap(t_swap_calc *swap_calc)
{
	return (swap_calc->a_display_swap);
}
