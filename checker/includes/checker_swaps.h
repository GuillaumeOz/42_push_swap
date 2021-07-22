/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_swaps.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:36:38 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/15 18:15:32 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_SWAPS_H
# define CHECKER_SWAPS_H

void	pa_swap(t_swap_calc *swap_calc, t_stack **a_stack,
			t_stack *b_stack);
void	pb_swap(t_swap_calc *swap_calc, t_stack **b_stack,
			t_stack *a_stack);

void	sa_swap(t_swap_calc *swap_calc, t_stack **a_stack);
void	sb_swap(t_swap_calc *swap_calc, t_stack **b_stack);
void	ss_swap(t_swap_calc *swap_calc, t_stack **a_stack, t_stack **b_stack);

void	ra_swap(t_swap_calc *swap_calc, t_stack **a_stack);
void	rb_swap(t_swap_calc *swap_calc, t_stack **b_stack);
void	rr_swap(t_swap_calc *swap_calc, t_stack **a_stack, t_stack **b_stack);

void	rra_swap(t_swap_calc *swap_calc, t_stack **a_stack);
void	rrb_swap(t_swap_calc *swap_calc, t_stack **b_stack);
void	rrr_swap(t_swap_calc *swap_calc, t_stack **a_stack, t_stack **b_stack);

#endif