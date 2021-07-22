/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parse_tab.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:02:58 by gozsertt          #+#    #+#             */
/*   Updated: 2021/07/16 14:18:38 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_tab_element_size(char **tab)
{
	size_t	size;
	bool	minus;
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		minus = false;
		size = ft_strlen(tab[i]);
		if (ft_ischar(tab[i], '-') == true)
			minus = true;
		if (minus == true && tab[i][0] != '-')
			push_swap_error("Error\n");
		if (minus == true && size > 11)
			push_swap_error("Error\n");
		else if (minus == false && size > 10)
			push_swap_error("Error\n");
		if (minus == true && size == 1)
			push_swap_error("Error\n");
		i++;
	}
}

static void	check_double_minus(char **tab)
{
	bool	minus;
	int		i;
	int		j;

	i = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		minus = false;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == '-')
			{
				if (minus == false)
					minus = true;
				else
					push_swap_error("Error\n");
			}	
			j++;
		}
		i++;
	}
}

static void	check_tab_value(char **tab)
{
	long	value;
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		value = ft_atol(tab[i]);
		if (value > INT_MAX)
			push_swap_error("Error\n");
		else if (value < INT_MIN)
			push_swap_error("Error\n");
		i++;
	}
}

static void	check_double_value(char **tab)
{
	bool	double_number;
	int		i;
	int		j;

	i = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		double_number = false;
		while (tab[j] != NULL)
		{
			if ((ft_strcmp(tab[i], tab[j]) == true) && double_number == false)
				double_number = true;
			else if ((ft_strcmp(tab[i], tab[j]) == true)
				&& double_number == true)
				push_swap_error("Error\n");
			j++;
		}
		i++;
	}
}

char	**parse_tab(char *argv)
{
	char	**tab;

	tab = ft_split(argv, ' ');
	check_tab_element_size(tab);
	check_double_minus(tab);
	check_tab_value(tab);
	check_double_value(tab);
	return (tab);
}
