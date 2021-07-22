/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_load_rr_way.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 14:49:07 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/20 19:32:09 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	deep_checker(t_stack *previous, t_stack *middle, t_stack *next)
{
	if (previous == NULL && get_stack_pos(middle) < get_stack_pos(next))
		return (true);
	else if (get_stack_pos(previous) < get_stack_pos(middle)
		&& get_stack_pos(middle) < get_stack_pos(next))
		return (true);
	return (false);
}

static void	calc_rr_right_pos(t_swap_calc *swap_calc, t_stack *tmp_a,
	 t_stack *tmp_b, int count)
{
	t_stack	*previous;
	char	*tmp_cmd_b;
	char	*tmp_cmd_a;

	tmp_cmd_b = NULL;
	tmp_cmd_a = NULL;
	previous = get_stack_last(tmp_a);
	while (count-- > 0)
		tmp_cmd_b = ft_strappend(tmp_cmd_b, "rb\n", true, false);
	count = (calc_stack_len(tmp_a));
	while (count > 0)
	{
		if (deep_checker(previous, tmp_b, tmp_a) == true)
			break ;
		tmp_cmd_a = ft_strappend(tmp_cmd_a, "ra\n", true, false);
		previous = tmp_a;
		tmp_a = get_stack_previous(tmp_a);
		count--;
	}
	compute_rr_cmd(swap_calc, tmp_cmd_b, tmp_cmd_a);
	free(tmp_cmd_b);
	free(tmp_cmd_a);
}

static void	load_rr_count(t_swap_calc *swap_calc, t_stack **a_stack,
	t_stack **b_stack, int count)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		tmp_count;
	int		size_max;

	if (swap_calc->tmp_rr_cmd == NULL)
		size_max = (get_swap_calc_b_stack_size(swap_calc) - 1);
	else if ((get_swap_calc_b_stack_size(swap_calc) - 1)
		< ((int)ft_strlen(swap_calc->tmp_rr_cmd) / 3))
		size_max = (get_swap_calc_b_stack_size(swap_calc) - 1);
	else
		size_max = (ft_strlen(swap_calc->tmp_rr_cmd) / 3);
	if (count > size_max)
		return ;
	tmp_count = count;
	tmp_a = get_stack_first((*a_stack));
	tmp_b = get_stack_first((*b_stack));
	while (tmp_count > 0)
	{
		tmp_b = get_stack_previous(tmp_b);
		tmp_count--;
	}
	calc_rr_right_pos(swap_calc, tmp_a, tmp_b, count);
	load_rr_count(swap_calc, a_stack, b_stack, count + 1);
}

void	load_rr_way(t_swap_calc *swap_calc, t_stack **a_stack,
	t_stack **b_stack)
{
	int	len;

	len = calc_stack_len((*b_stack));
	set_swap_calc_b_stack_size(swap_calc, len);
	load_rr_count(swap_calc, a_stack, b_stack, 0);
}
