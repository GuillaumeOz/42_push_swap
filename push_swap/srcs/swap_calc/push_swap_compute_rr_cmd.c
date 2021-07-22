/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_compute_rr_cmd.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 10:56:42 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/20 20:04:53 by gozsertt         ###   ########.fr       */
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
	if (swap_calc->tmp_rr_cmd != NULL)
		save_cmd_len = ft_strlen(swap_calc->tmp_rr_cmd);
	else
		save_cmd_len = 0;
	if (save_cmd_len == 0 && result_cmd != NULL)
		swap_calc->tmp_rr_cmd = ft_strdup(result_cmd);
	else if (new_cmd_len < save_cmd_len)
	{
		free(swap_calc->tmp_rr_cmd);
		swap_calc->tmp_rr_cmd = ft_strdup(result_cmd);
	}
	free(result_cmd);
}

static void	lower_rb(int size_a, int size_b, char **result_cmd)
{
	int		tmp;

	tmp = size_b / 3;
	while (tmp-- > 0)
		(*result_cmd) = ft_strappend((*result_cmd), "rr\n", true, false);
	tmp = (size_a - size_b) / 3;
	while (tmp-- > 0)
		(*result_cmd) = ft_strappend((*result_cmd), "ra\n", true, false);
}

static void	lower_ra(int size_a, int size_b, char **result_cmd)
{
	int		tmp;

	tmp = size_a / 3;
	while (tmp-- > 0)
		(*result_cmd) = ft_strappend((*result_cmd), "rr\n", true, false);
	tmp = (size_b - size_a) / 3;
	while (tmp-- > 0)
		(*result_cmd) = ft_strappend((*result_cmd), "rb\n", true, false);
}

static void	secure_size_setter(char *tmp_cmd_a, char *tmp_cmd_b,
	int *size_a, int *size_b)
{
	if (tmp_cmd_b != NULL)
		*size_b = ft_strlen(tmp_cmd_b);
	else
		*size_b = 0;
	if (tmp_cmd_a != NULL)
		*size_a = ft_strlen(tmp_cmd_a);
	else
		*size_a = 0;
}

void	compute_rr_cmd(t_swap_calc *swap_calc, char *tmp_cmd_b,
	char *tmp_cmd_a)
{
	char	*result_cmd;
	int		size_b;
	int		size_a;
	int		tmp;

	result_cmd = NULL;
	secure_size_setter(tmp_cmd_a, tmp_cmd_b, &size_a, &size_b);
	if (size_b < size_a)
		lower_rb(size_a, size_b, &result_cmd);
	else if (size_b > size_a)
		lower_ra(size_a, size_b, &result_cmd);
	else if (size_b == size_a)
	{
		tmp = size_a / 3;
		while (tmp-- > 0)
			result_cmd = ft_strappend(result_cmd, "rr\n", true, false);
	}
	change_save_cmd(swap_calc, result_cmd);
}
