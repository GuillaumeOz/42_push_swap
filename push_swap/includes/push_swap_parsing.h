/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 18:30:10 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/05 18:33:39 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_PARSING_H
# define PUSH_SWAP_PARSING_H

void		set_elements_pos(t_stack *a_stack);
t_stack		*parse_a_stack(char **tab);
char		**parse_tab(char *argv);
void		parsing(t_stack **a_stack, int argc, char **argv);

#endif