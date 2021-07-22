/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_parsing.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 18:30:10 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/16 12:48:08 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_PARSING_H
# define CHECKER_PARSING_H

int			checker_get_next_line(int fd, char **line);
void		set_elements_pos(t_stack *a_stack);
t_stack		*parse_a_stack(char **tab);
char		**parse_tab(char *argv);
void		parsing(t_stack **a_stack, int argc, char **argv);

#endif