/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 15:37:25 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/20 16:59:25 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	quit_checker(t_swap_calc *swap_calc, t_stack *a_stack)
{
	write(1, "OK\n", 3);
	free_stack_list(a_stack);
	free_swap_calc(swap_calc);
	exit(EXIT_SUCCESS);
}

static bool	over_check(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*tmp;

	if ((*b_stack) != NULL)
		return (false);
	tmp = get_stack_first((*a_stack));
	while (tmp->previous != NULL)
	{
		if (get_stack_pos(tmp) > get_stack_pos(tmp->previous))
			return (false);
		tmp = get_stack_previous(tmp);
	}
	return (true);
}

static bool	check_over(t_swap_calc *swap_calc, t_stack **a_stack,
	t_stack **b_stack)
{
	int	len;

	len = get_swap_calc_stack_size(swap_calc);
	if (len == 1)
		return (true);
	if (get_stack_first((*a_stack)) == get_stack_first((*b_stack)))
		(*b_stack) = NULL;
	if (over_check(a_stack, b_stack) == true)
		return (true);
	return (false);
}

static void	check_cmd_list(char *line, t_swap_calc *swap_calc,
	t_stack **a_stack, t_stack **b_stack)
{
	if (ft_strcmp(line, "pa") == true)
		pa_swap(swap_calc, a_stack, *b_stack);
	else if (ft_strcmp(line, "pb") == true)
		pb_swap(swap_calc, b_stack, *a_stack);
	else if (ft_strcmp(line, "sa") == true)
		sa_swap(swap_calc, a_stack);
	else if (ft_strcmp(line, "sb") == true)
		sb_swap(swap_calc, b_stack);
	else if (ft_strcmp(line, "ss") == true)
		ss_swap(swap_calc, a_stack, b_stack);
	else if (ft_strcmp(line, "ra") == true)
		ra_swap(swap_calc, a_stack);
	else if (ft_strcmp(line, "rb") == true)
		rb_swap(swap_calc, b_stack);
	else if (ft_strcmp(line, "rr") == true)
		rr_swap(swap_calc, a_stack, b_stack);
	else if (ft_strcmp(line, "rra") == true)
		rra_swap(swap_calc, a_stack);
	else if (ft_strcmp(line, "rrb") == true)
		rrb_swap(swap_calc, b_stack);
	else if (ft_strcmp(line, "rrr") == true)
		rrr_swap(swap_calc, a_stack, b_stack);
	else
		checker_error("Error\n");
}

int	main(int argc, char **argv)
{
	t_swap_calc	*swap_calc;
	t_stack		*a_stack;
	t_stack		*b_stack;
	char		*line;

	b_stack = NULL;
	parsing(&a_stack, argc, argv);
	swap_calc = malloc_swap_calc(calc_stack_len(a_stack));
	while (checker_get_next_line(0, &line) > 0)
	{
		check_cmd_list(line, swap_calc, &a_stack, &b_stack);
		free(line);
	}
	if (ft_strlen(line) != 0)
	{
		free(line);
		checker_error("Error\n");
	}
	free(line);
	if (check_over(swap_calc, &a_stack, &b_stack) == true)
		quit_checker(swap_calc, a_stack);
	write(1, "KO\n", 3);
	exit(EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
