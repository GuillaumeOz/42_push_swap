/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:37:06 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/20 18:33:32 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quit(t_swap_calc *swap_calc, t_stack *a_stack)
{
	free_stack_list(a_stack);
	free_swap_calc(swap_calc);
	exit(EXIT_SUCCESS);
}

static void	print_cmd(t_swap_calc *swap_calc)
{
	char	*cmd;
	size_t	len;

	cmd = get_swap_calc_cmd(swap_calc);
	if (cmd != NULL)
	{
		len = ft_strlen(cmd);
		write(1, cmd, len);
	}
}

int	main(int argc, char **argv)
{
	t_swap_calc	*swap_calc;
	t_stack		*a_stack;

	parsing(&a_stack, argc, argv);
	swap_calc = malloc_swap_calc(calc_stack_len(a_stack));
	start_sort(swap_calc, a_stack);
	print_cmd(swap_calc);
	quit(swap_calc, a_stack);
	return (EXIT_SUCCESS);
}
