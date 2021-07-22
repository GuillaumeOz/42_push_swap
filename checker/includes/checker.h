/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 15:38:44 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/20 15:54:31 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <limits.h>
# include "../libft/includes/libft.h"
# include "checker_t_stack.h"
# include "checker_t_swap_calc.h"
# include "checker_error.h"
# include "checker_parsing.h"
# include "checker_swaps.h"

void	quit_checker(t_swap_calc *swap_calc, t_stack *a_stack);

#endif