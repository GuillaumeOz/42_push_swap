/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_t_swap_calc_rr_setter.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 00:14:39 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/16 13:11:51 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	set_swap_calc_rr_tmp(t_swap_calc *swap_calc, bool value)
{
	swap_calc->rr_tmp = value;
}
