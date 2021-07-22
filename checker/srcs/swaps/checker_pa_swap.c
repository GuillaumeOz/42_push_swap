/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_pa_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:24:12 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/20 16:04:00 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static bool	pa_swap_checker(t_stack *b_stack)
{
	int	len;

	if (b_stack == NULL)
		return (false);
	len = calc_stack_len(b_stack);
	if (len == 0)
		return (false);
	return (true);
}

static void	pa_swap_exec(t_stack **first_a, t_stack *first_b,
	t_stack *first_b_previous)
{
	if ((*first_a) != NULL)
	{
		set_stack_next((*first_a), first_b);
		set_stack_previous(first_b, (*first_a));
		set_stack_next(first_b, NULL);
	}
	else
	{
		(*first_a) = first_b;
		set_stack_previous((*first_a), NULL);
		set_stack_next((*first_a), NULL);
	}
	if (first_b_previous != NULL)
		set_stack_next(first_b_previous, NULL);
}

void	pa_swap(t_swap_calc *swap_calc, t_stack **a_stack, t_stack *b_stack)
{
	t_stack	*first_b;
	t_stack	*first_b_previous;

	if (pa_swap_checker(b_stack) == false)
		return ;
	if ((*a_stack) != NULL)
		while ((*a_stack)->next != NULL)
			(*a_stack) = (*a_stack)->next;
	while (b_stack->next != NULL)
		b_stack = b_stack->next;
	first_b = b_stack;
	first_b_previous = first_b->previous;
	if (first_b_previous == NULL)
		b_stack = NULL;
	pa_swap_exec(a_stack, first_b, first_b_previous);
	if (get_swap_calc_a_display_swap(swap_calc) == true)
		swap_calc->cmd = ft_strappend(swap_calc->cmd, "pa\n", true, false);
	refresh_a_stack(swap_calc, a_stack);
	refresh_b_stack(swap_calc, &b_stack);
}
