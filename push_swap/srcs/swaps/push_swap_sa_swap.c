/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sa_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:25:14 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/16 13:50:57 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	sa_swap_checker(t_stack *a_stack)
{
	int	len;

	if (a_stack == NULL)
		return (false);
	len = calc_stack_len(a_stack);
	if (len == 1)
		return (false);
	return (true);
}

static void	sa_swap_exec(t_stack *first, t_stack *second, t_stack *third)
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

void	sa_swap(t_swap_calc *swap_calc, t_stack **a_stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (sa_swap_checker((*a_stack)) == false)
		return ;
	while ((*a_stack)->next != NULL)
		(*a_stack) = (*a_stack)->next;
	first = (*a_stack);
	second = first->previous;
	if (second->previous != NULL)
		third = second->previous;
	else
		third = NULL;
	sa_swap_exec(first, second, third);
	if (get_swap_calc_a_display_swap(swap_calc) == true)
		swap_calc->cmd = ft_strappend(swap_calc->cmd, "sa\n", true, false);
	refresh_a_stack(swap_calc, a_stack);
}
