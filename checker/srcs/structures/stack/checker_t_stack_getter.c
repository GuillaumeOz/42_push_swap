/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_t_stack_getter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:14:52 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/16 13:13:27 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*get_stack_previous(t_stack *stack)
{
	return (stack->previous);
}

t_stack	*get_stack_next(t_stack *stack)
{
	return (stack->next);
}

bool	get_stack_over(t_stack *stack)
{
	return (stack->over);
}

int	get_stack_number(t_stack *stack)
{
	return (stack->number);
}

int	get_stack_pos(t_stack *stack)
{
	return (stack->pos);
}
