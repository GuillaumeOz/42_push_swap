/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotation_counter.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 09:44:18 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/20 19:50:51 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_rr_cmd(char *rr_cmd)
{
	int	len;

	if (rr_cmd != NULL)
	{
		len = ft_strlen(rr_cmd);
		len = len / 3;
	}
	else
		len = 0;
	return (len);
}

int	count_rrr_cmd(char *rrr_cmd)
{
	int	len;

	if (rrr_cmd != NULL)
	{
		len = ft_strlen(rrr_cmd);
		len = len / 4;
	}
	else
		len = 0;
	return (len);
}

int	count_ra_rrb_cmd(char *ra_rrb_cmd)
{
	size_t	len;

	len = ft_count_elems(ra_rrb_cmd, '\n');
	return ((int)len);
}

int	count_rb_rra_cmd(char *rb_rra_cmd)
{
	size_t	len;

	len = ft_count_elems(rb_rra_cmd, '\n');
	return ((int)len);
}
