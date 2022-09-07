/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:56:26 by asanotomoki       #+#    #+#             */
/*   Updated: 2022/05/06 15:06:14 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*res;

	if (size == 0 || count == 0)
	{
		size = 1;
		count = 1;
	}
	total_size = size * count;
	if (size != total_size / count)
		return (NULL);
	res = malloc(total_size);
	if (res == NULL)
		return (NULL);
	ft_bzero(res, total_size);
	return (res);
}
