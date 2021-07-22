/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_t_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:03:47 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/19 11:02:04 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*malloc_stack(int number)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		push_swap_error("Error\n");
	*stack = create_stack(number);
	return (stack);
}

t_stack	create_stack(int number)
{
	t_stack	stack;

	stack.pos = 0;
	stack.number = number;
	stack.over = false;
	stack.previous = NULL;
	stack.next = NULL;
	return (stack);
}

void	destroy_stack(t_stack to_destroy)
{
	ft_memset(&to_destroy, 0, sizeof(t_stack));
}

void	free_stack(t_stack *to_free)
{
	destroy_stack(*to_free);
	free(to_free);
}

void	free_stack_list(t_stack *to_free)
{
	t_stack	*tmp;

	while (to_free->previous != NULL)
		to_free = to_free->previous;
	while (to_free != NULL)
	{
		tmp = to_free->next;
		free_stack(to_free);
		to_free = tmp;
	}
}
