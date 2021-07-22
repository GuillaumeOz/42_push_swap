/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_t_stack.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 18:52:37 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/19 15:28:16 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_T_STACK_H
# define PUSH_SWAP_T_STACK_H

typedef struct s_stack
{
	int				pos;
	int				number;
	bool			over;
	struct s_stack	*previous;
	struct s_stack	*next;
}				t_stack;

t_stack	*malloc_stack(int number);
t_stack	create_stack(int number);
void	destroy_stack(t_stack to_destroy);
void	free_stack(t_stack *to_free);
void	free_stack_list(t_stack *to_free);

void	set_stack_previous(t_stack *stack, t_stack *value);
void	set_stack_next(t_stack *stack, t_stack *value);
void	set_stack_over(t_stack *stack, bool value);
void	set_stack_number(t_stack *stack, int value);
void	set_stack_pos(t_stack *stack, int value);

t_stack	*get_stack_previous(t_stack *stack);
t_stack	*get_stack_next(t_stack *stack);
bool	get_stack_over(t_stack *stack);
int		get_stack_number(t_stack *stack);
int		get_stack_pos(t_stack *stack);

t_stack	*get_stack_first(t_stack *stack);
t_stack	*get_stack_last(t_stack *stack);

#endif