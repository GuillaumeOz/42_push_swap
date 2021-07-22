/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 10:40:15 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/16 11:34:10 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_SORT_H
# define PUSH_SWAP_SORT_H

int		count_rr_cmd(char *rr_cmd);
int		count_rrr_cmd(char *rrr_cmd);
int		count_ra_rrb_cmd(char *ra_rrb_cmd);
int		count_rb_rra_cmd(char *rb_rra_cmd);

void	compute_rr_cmd(t_swap_calc *swap_calc, char *tmp_cmd_b,
			char *tmp_cmd_a);
void	compute_rrr_cmd(t_swap_calc *swap_calc, char *tmp_cmd_b,
			char *tmp_cmd_a);

void	load_rr_way(t_swap_calc *swap_calc, t_stack **a_stack,
			t_stack **b_stack);
void	load_rrr_way(t_swap_calc *swap_calc, t_stack **a_stack,
			t_stack **b_stack);
void	load_ra_rrb_way(t_swap_calc *swap_calc, t_stack **a_stack,
			t_stack **b_stack);
void	load_rb_rra_way(t_swap_calc *swap_calc, t_stack **a_stack,
			t_stack **b_stack);

void	apply_rr_cmd(t_swap_calc *swap_calc, t_stack **a_stack,
			t_stack **b_stack);
void	apply_rrr_cmd(t_swap_calc *swap_calc, t_stack **a_stack,
			t_stack **b_stack);
void	apply_ra_rrb_cmd(t_swap_calc *swap_calc, t_stack **a_stack,
			t_stack **b_stack);
void	apply_rb_rra_cmd(t_swap_calc *swap_calc, t_stack **a_stack,
			t_stack **b_stack);

void	backtracking_sort(t_swap_calc *swap_calc, t_stack **a_stack,
			t_stack **b_stack);

void	initial_low_sort(t_swap_calc *swap_calc, t_stack **a_stack,
			t_stack **b_stack);
void	initial_medium_sort(t_swap_calc *swap_calc, t_stack **a_stack,
			t_stack **b_stack);
void	initial_long_sort(t_swap_calc *swap_calc, t_stack **a_stack,
			t_stack **b_stack);

bool	low_sort(t_swap_calc *swap_calc);
bool	medium_sort(t_swap_calc *swap_calc);
bool	long_sort(t_swap_calc *swap_calc);

bool	low_b_sort(t_swap_calc *swap_calc, t_stack **b_stack);
bool	low_a_sort(t_swap_calc *swap_calc, t_stack **a_stack);

void	start_sort(t_swap_calc *swap_calc, t_stack *a_stack);

#endif