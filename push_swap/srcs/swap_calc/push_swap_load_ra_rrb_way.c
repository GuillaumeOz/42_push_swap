/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_load_ra_rrb_way.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 11:29:59 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/20 20:06:45 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	change_save_cmd(t_swap_calc *swap_calc, char *result_cmd)
{
	int	new_cmd_len;
	int	save_cmd_len;

	if (result_cmd != NULL)
		new_cmd_len = ft_strlen(result_cmd);
	else
		new_cmd_len = 0;
	if (swap_calc->tmp_ra_rrb_cmd != NULL)
		save_cmd_len = ft_strlen(swap_calc->tmp_ra_rrb_cmd);
	else
		save_cmd_len = 0;
	if (save_cmd_len == 0 && result_cmd != NULL)
		swap_calc->tmp_ra_rrb_cmd = ft_strdup(result_cmd);
	else if (new_cmd_len < save_cmd_len)
	{
		free(swap_calc->tmp_ra_rrb_cmd);
		swap_calc->tmp_ra_rrb_cmd = ft_strdup(result_cmd);
	}
	free(result_cmd);
}

static bool	deep_checker(t_stack *previous, t_stack *middle, t_stack *next)
{
	if (previous == NULL && get_stack_pos(middle) < get_stack_pos(next))
		return (true);
	else if (get_stack_pos(previous) < get_stack_pos(middle)
		&& get_stack_pos(middle) < get_stack_pos(next))
		return (true);
	return (false);
}

static void	calc_ra_rrb_right_pos(t_swap_calc *swap_calc, t_stack *tmp_a,
	 t_stack *tmp_b, int count)
{
	t_stack	*previous;
	char	*tmp_cmd_b;
	char	*tmp_cmd_a;
	char	*result_cmd;

	tmp_cmd_b = ft_strdup("rrb\n");
	tmp_cmd_a = NULL;
	previous = get_stack_last(tmp_a);
	while (count-- > 0)
		tmp_cmd_b = ft_strappend(tmp_cmd_b, "rrb\n", true, false);
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
	result_cmd = ft_strappend(tmp_cmd_a, tmp_cmd_b, false, false);
	change_save_cmd(swap_calc, result_cmd);
	free(tmp_cmd_b);
	free(tmp_cmd_a);
}

static void	load_ra_rrb_count(t_swap_calc *swap_calc, t_stack **a_stack,
	t_stack **b_stack, int count)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		tmp_count;
	int		size_max;

	if (swap_calc->tmp_ra_rrb_cmd == NULL)
		size_max = (get_swap_calc_b_stack_size(swap_calc) - 1);
	else if ((get_swap_calc_b_stack_size(swap_calc) - 1)
		< ((int)ft_count_elems(swap_calc->tmp_ra_rrb_cmd, '\n')))
		size_max = (get_swap_calc_b_stack_size(swap_calc) - 1);
	else
		size_max = (ft_count_elems(swap_calc->tmp_ra_rrb_cmd, '\n'));
	if (count > size_max)
		return ;
	tmp_count = count;
	tmp_a = get_stack_first((*a_stack));
	tmp_b = get_stack_last((*b_stack));
	while (tmp_count > 0)
	{
		tmp_b = get_stack_next(tmp_b);
		tmp_count--;
	}
	calc_ra_rrb_right_pos(swap_calc, tmp_a, tmp_b, count);
	load_ra_rrb_count(swap_calc, a_stack, b_stack, count + 1);
}

void	load_ra_rrb_way(t_swap_calc *swap_calc, t_stack **a_stack,
	t_stack **b_stack)
{
	int	len;

	len = calc_stack_len((*b_stack));
	set_swap_calc_b_stack_size(swap_calc, len);
	load_ra_rrb_count(swap_calc, a_stack, b_stack, 0);
}
