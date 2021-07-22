/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_pb_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:24:36 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/16 13:07:29 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static bool	pb_swap_checker(t_stack *a_stack)
{
	int	len;

	if (a_stack == NULL)
		return (false);
	len = calc_stack_len(a_stack);
	if (len == 0)
		return (false);
	return (true);
}

static void	pb_swap_exec(t_stack **first_b, t_stack *first_a,
	t_stack *first_a_previous)
{
	if ((*first_b) != NULL)
	{
		set_stack_next((*first_b), first_a);
		set_stack_previous(first_a, (*first_b));
		set_stack_next(first_a, NULL);
	}
	else
	{
		(*first_b) = first_a;
		set_stack_previous((*first_b), NULL);
		set_stack_next((*first_b), NULL);
	}
	if (first_a_previous != NULL)
		set_stack_next(first_a_previous, NULL);
}

void	pb_swap(t_swap_calc *swap_calc, t_stack **b_stack, t_stack *a_stack)
{
	t_stack	*first_a;
	t_stack	*first_a_previous;

	if (pb_swap_checker(a_stack) == false)
		return ;
	if ((*b_stack) != NULL)
		while ((*b_stack)->next != NULL)
			(*b_stack) = (*b_stack)->next;
	while (a_stack->next != NULL)
		a_stack = a_stack->next;
	first_a = a_stack;
	first_a_previous = first_a->previous;
	if (first_a_previous == NULL)
		a_stack = NULL;
	pb_swap_exec(b_stack, first_a, first_a_previous);
	if (get_swap_calc_b_display_swap(swap_calc) == true)
		swap_calc->cmd = ft_strappend(swap_calc->cmd, "pb\n", true, false);
	refresh_a_stack(swap_calc, &a_stack);
	refresh_b_stack(swap_calc, b_stack);
}
