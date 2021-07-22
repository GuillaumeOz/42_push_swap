/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:47:03 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/20 14:12:53 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "../libft/includes/libft.h"
# include "push_swap_t_stack.h"
# include "push_swap_t_swap_calc.h"
# include "push_swap_error.h"
# include "push_swap_parsing.h"
# include "push_swap_swaps.h"
# include "push_swap_sort.h"

void	quit(t_swap_calc *swap_calc, t_stack *a_stack);

#endif