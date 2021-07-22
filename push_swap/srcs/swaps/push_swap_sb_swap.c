/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sb_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:25:23 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/16 13:50:43 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	sb_swap_checker(t_stack *b_stack)
{
	int	len;

	if (b_stack == NULL)
		return (false);
	len = calc_stack_len(b_stack);
	if (len == 1)
		return (false);
	return (true);
}

static void	sb_swap_exec(t_stack *first, t_stack *second, t_stack *third)
{
	if (third != NULL)
	{
		set_stack_next(third, first);
		set_stack_previous(first, third);
	}
	else
		set_stack_previous(first, third);
	set_stack_previous(second, first);
	set_stack_next(first, second);
	set_stack_next(second, NULL);
}

void	sb_swap(t_swap_calc *swap_calc, t_stack **b_stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (sb_swap_checker((*b_stack)) == false)
		return ;
	while ((*b_stack)->next != NULL)
		(*b_stack) = (*b_stack)->next;
	first = (*b_stack);
	second = first->previous;
	if (second->previous != NULL)
		third = second->previous;
	else
		third = NULL;
	sb_swap_exec(first, second, third);
	if (get_swap_calc_b_display_swap(swap_calc) == true)
		swap_calc->cmd = ft_strappend(swap_calc->cmd, "sb\n", true, false);
	refresh_b_stack(swap_calc, b_stack);
}
