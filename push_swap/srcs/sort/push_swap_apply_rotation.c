/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_apply_rotation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 09:50:34 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/20 20:04:56 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_rrr_cmd(t_swap_calc *swap_calc, t_stack **a_stack,
	t_stack **b_stack)
{
	char	**tab;
	int		i;

	i = 0;
	if (swap_calc->tmp_rrr_cmd != NULL)
	{
		tab = ft_split(swap_calc->tmp_rrr_cmd, '\n');
		while (tab[i] != NULL)
		{
			if (ft_strcmp(tab[i], "rra") == true)
				rra_swap(swap_calc, a_stack);
			else if (ft_strcmp(tab[i], "rrb") == true)
				rrb_swap(swap_calc, b_stack);
			else if (ft_strcmp(tab[i], "rrr") == true)
				rrr_swap(swap_calc, a_stack, b_stack);
			i++;
		}
		ft_tab_free(tab);
	}
	pa_swap(swap_calc, a_stack, *b_stack);
	if (get_stack_first((*a_stack)) == get_stack_first((*b_stack)))
		(*b_stack) = NULL;
}

void	apply_rr_cmd(t_swap_calc *swap_calc, t_stack **a_stack,
	t_stack **b_stack)
{
	char	**tab;
	int		i;

	i = 0;
	if (swap_calc->tmp_rr_cmd != NULL)
	{
		tab = ft_split(swap_calc->tmp_rr_cmd, '\n');
		while (tab[i] != NULL)
		{
			if (ft_strcmp(tab[i], "ra") == true)
				ra_swap(swap_calc, a_stack);
			else if (ft_strcmp(tab[i], "rb") == true)
				rb_swap(swap_calc, b_stack);
			else if (ft_strcmp(tab[i], "rr") == true)
				rr_swap(swap_calc, a_stack, b_stack);
			i++;
		}
		ft_tab_free(tab);
	}
	pa_swap(swap_calc, a_stack, *b_stack);
	if (get_stack_first((*a_stack)) == get_stack_first((*b_stack)))
		(*b_stack) = NULL;
}

void	apply_ra_rrb_cmd(t_swap_calc *swap_calc, t_stack **a_stack,
	t_stack **b_stack)
{
	char	**tab;
	int		i;

	i = 0;
	if (swap_calc->tmp_ra_rrb_cmd != NULL)
	{
		tab = ft_split(swap_calc->tmp_ra_rrb_cmd, '\n');
		while (tab[i] != NULL)
		{
			if (ft_strcmp(tab[i], "ra") == true)
				ra_swap(swap_calc, a_stack);
			else if (ft_strcmp(tab[i], "rrb") == true)
				rrb_swap(swap_calc, b_stack);
			i++;
		}
		ft_tab_free(tab);
	}
	pa_swap(swap_calc, a_stack, *b_stack);
	if (get_stack_first((*a_stack)) == get_stack_first((*b_stack)))
		(*b_stack) = NULL;
}

void	apply_rb_rra_cmd(t_swap_calc *swap_calc, t_stack **a_stack,
	t_stack **b_stack)
{
	char	**tab;
	int		i;

	i = 0;
	if (swap_calc->tmp_rb_rra_cmd != NULL)
	{
		tab = ft_split(swap_calc->tmp_rb_rra_cmd, '\n');
		while (tab[i] != NULL)
		{
			if (ft_strcmp(tab[i], "rb") == true)
				rb_swap(swap_calc, b_stack);
			else if (ft_strcmp(tab[i], "rra") == true)
				rra_swap(swap_calc, a_stack);
			i++;
		}
		ft_tab_free(tab);
	}
	pa_swap(swap_calc, a_stack, *b_stack);
	if (get_stack_first((*a_stack)) == get_stack_first((*b_stack)))
		(*b_stack) = NULL;
}
