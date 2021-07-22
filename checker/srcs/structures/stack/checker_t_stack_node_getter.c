/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_t_stack_node_getter.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 11:47:26 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/16 13:13:06 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*get_stack_first(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next != NULL)
		stack = get_stack_next(stack);
	return (stack);
}

t_stack	*get_stack_last(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->previous != NULL)
		stack = get_stack_previous(stack);
	return (stack);
}
