/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:58:52 by tasano            #+#    #+#             */
/*   Updated: 2022/06/12 00:42:59 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dst != NULL)
		i = ft_strlen(dst);
	else
		i = 0;
	if (dstsize <= i)
		return (dstsize + ft_strlen(src));
	return (i + ft_strlcpy(dst + i, src, dstsize - i));
}
