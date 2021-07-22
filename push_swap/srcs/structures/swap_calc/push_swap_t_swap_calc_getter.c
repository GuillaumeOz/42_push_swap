/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_t_swap_calc_getter.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:37:31 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/16 14:03:35 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_swap_calc_stack_size(t_swap_calc *swap_calc)
{
	return (swap_calc->stack_size);
}

char	*get_swap_calc_cmd(t_swap_calc *swap_calc)
{
	return (swap_calc->cmd);
}

int	get_swap_calc_high(t_swap_calc *swap_calc)
{
	return (swap_calc->high);
}

int	get_swap_calc_median(t_swap_calc *swap_calc)
{
	return (swap_calc->median);
}

int	get_swap_calc_low(t_swap_calc *swap_calc)
{
	return (swap_calc->low);
}
