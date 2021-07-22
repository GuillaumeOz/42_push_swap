/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_t_swap_calc.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:31:31 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/16 13:30:34 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_T_SWAP_CALC_H
# define PUSH_SWAP_T_SWAP_CALC_H

typedef struct s_swap_calc
{
	int		stack_size;
	int		a_stack_size;
	bool	a_display_swap;
	int		b_stack_size;
	bool	b_display_swap;
	char	*cmd;
	int		tmp_pos;
	int		chain_pos;
	int		low;
	int		median;
	int		high;
	bool	rr_tmp;
	bool	rrr_tmp;
	int		rr_count;
	int		rrr_count;
	int		ra_rrb_count;
	int		rb_rra_count;
	char	*tmp_rr_cmd;
	char	*tmp_rrr_cmd;
	char	*tmp_ra_rrb_cmd;
	char	*tmp_rb_rra_cmd;
}				t_swap_calc;

/*
**	t_swap_calc constructor / destructor
*/

t_swap_calc	*malloc_swap_calc(int stack_size);
t_swap_calc	create_swap_calc(int stack_size);
void		destroy_swap_calc(t_swap_calc swap_calc);
void		free_swap_calc(t_swap_calc *swap_calc);

/*
**	t_swap_calc getter / setter
*/

int			get_swap_calc_stack_size(t_swap_calc *swap_calc);
char		*get_swap_calc_cmd(t_swap_calc *swap_calc);
int			get_swap_calc_high(t_swap_calc *swap_calc);
int			get_swap_calc_median(t_swap_calc *swap_calc);
int			get_swap_calc_low(t_swap_calc *swap_calc);

void		set_swap_calc_stack_size(t_swap_calc *swap_calc, int value);
void		set_swap_calc_high(t_swap_calc *swap_calc, int value);
void		set_swap_calc_median(t_swap_calc *swap_calc, int value);

void		set_swap_calc_cmd(t_swap_calc *swap_calc, char *cmd);
void		set_swap_calc_rr_tmp(t_swap_calc *swap_calc, bool value);
void		set_swap_calc_rrr_tmp(t_swap_calc *swap_calc, bool value);

/*
**	t_swap_calc a_stack getter / setter
*/

int			get_swap_calc_a_stack_size(t_swap_calc *swap_calc);
bool		get_swap_calc_a_display_swap(t_swap_calc *swap_calc);

void		set_swap_calc_a_display_swap(t_swap_calc *swap_calc, bool value);
void		set_swap_calc_a_stack_size(t_swap_calc *swap_calc, int value);

/*
**	t_swap_calc b_stack getter / setter
*/

int			get_swap_calc_b_stack_size(t_swap_calc *swap_calc);
bool		get_swap_calc_b_display_swap(t_swap_calc *swap_calc);

void		set_swap_calc_b_stack_size(t_swap_calc *swap_calc, int value);
void		set_swap_calc_b_display_swap(t_swap_calc *swap_calc, bool value);

/*
**	t_swap_calc calc_fct
*/

bool		sb_swap_case(t_swap_calc *swap_calc, t_stack **a_stack);
bool		rb_swap_case(t_swap_calc *swap_calc, t_stack **a_stack);
bool		rrb_swap_case(t_swap_calc *swap_calc, t_stack **a_stack);
bool		sb_rrb_swap_case(t_swap_calc *swap_calc, t_stack **a_stack);
bool		sb_rb_swap_case(t_swap_calc *swap_calc, t_stack **a_stack);

bool		sa_swap_case(t_swap_calc *swap_calc, t_stack **a_stack);
bool		ra_swap_case(t_swap_calc *swap_calc, t_stack **a_stack);
bool		rra_swap_case(t_swap_calc *swap_calc, t_stack **a_stack);
bool		sa_rra_swap_case(t_swap_calc *swap_calc, t_stack **a_stack);
bool		sa_ra_swap_case(t_swap_calc *swap_calc, t_stack **a_stack);

bool		over_check(t_stack **a_stack, t_stack **b_stack);

void		set_low_start(t_swap_calc *swap_calc, t_stack **a_stack);

void		refresh_a_stack(t_swap_calc *swap_calc, t_stack **a_stack);
void		refresh_b_stack(t_swap_calc *swap_calc, t_stack **b_stack);
int			calc_stack_len(t_stack *stack);

#endif