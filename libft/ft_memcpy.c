/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 18:55:23 by tasano            #+#    #+#             */
/*   Updated: 2022/06/13 11:42:57 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*c_dst;
	const char	*s_cpy;
	size_t		i;

	if (dst == NULL && src == NULL)
		return (dst);
	c_dst = (char *)dst;
	s_cpy = (const char *)src;
	i = 0;
	while (i < n)
	{
		c_dst[i] = s_cpy[i];
		i++;
	}
	return (dst);
}
