/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_calc_stack_len.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:53:33 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/16 13:48:07 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_stack_len(t_stack *stack)
{
	int	len;

	len = 0;
	if (stack != NULL)
	{
		while (stack->previous != NULL)
			stack = get_stack_previous(stack);
	}
	while (stack != NULL)
	{
		stack = get_stack_next(stack);
		len++;
	}
	return (len);
}
