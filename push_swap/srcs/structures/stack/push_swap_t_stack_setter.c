/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_t_stack_setter.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:22:44 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/30 17:53:48 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_stack_previous(t_stack *stack, t_stack *value)
{
	stack->previous = value;
}

void	set_stack_next(t_stack *stack, t_stack *value)
{
	stack->next = value;
}

void	set_stack_over(t_stack *stack, bool value)
{
	stack->over = value;
}

void	set_stack_number(t_stack *stack, int value)
{
	stack->number = value;
}

void	set_stack_pos(t_stack *stack, int value)
{
	stack->pos = value;
}
