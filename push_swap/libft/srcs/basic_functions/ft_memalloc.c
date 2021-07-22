/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 17:24:30 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/29 14:39:21 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*ptr;

	ptr = NULL;
	if (size != 0)
	{
		ptr = (unsigned char *)malloc(sizeof(char) * size);
		if (ptr == NULL)
			ft_error("Error\n");
		ft_memset(ptr, 0, size);
	}
	else
		ft_error("Error\n");
	return ((void *)ptr);
}
