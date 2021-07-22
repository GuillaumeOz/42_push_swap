/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 18:38:57 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/16 13:15:53 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	check_single_argument_content(char *arg)
{
	bool	find;
	int		i;

	i = 0;
	find = false;
	if (ft_strlen(arg) == 0)
		checker_error("Error\n");
	while (arg[i] != '\0')
	{
		if (ft_ischar("0123456789", arg[i]) == true)
			find = true;
		i++;
	}
	if (find == false)
		checker_error("Error\n");
}

static void	check_argument_content(char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (ft_ischar(" -0123456789", charset[i]) == false)
			checker_error("Error\n");
		i++;
	}
}

static char	*join_arguments(int argc, char **argv)
{
	char	*arg;
	int		i;

	arg = ft_strdup("");
	if (arg == NULL)
		checker_error("Error\n");
	i = 1;
	while (i < argc)
	{
		check_single_argument_content(argv[i]);
		arg = ft_strprepend(arg, argv[i], true, false);
		if (arg == NULL)
			checker_error("Error\n");
		arg = ft_strprepend(arg, " ", true, false);
		if (arg == NULL)
			checker_error("Error\n");
		check_argument_content(arg);
		i++;
	}
	return (arg);
}

void	parsing(t_stack **a_stack, int argc, char **argv)
{
	char	**tab;
	char	*arg;

	if (argc < 2)
		exit(EXIT_FAILURE);
	arg = join_arguments(argc, argv);
	tab = parse_tab(arg);
	(*a_stack) = parse_a_stack(tab);
	free(arg);
	ft_tab_free(tab);
}
