/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanotomoki <asanotomoki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:59:27 by tasano            #+#    #+#             */
/*   Updated: 2022/03/18 02:05:33 by asanotomoki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s_move;
	unsigned char		*d_move;
	size_t				i;

	if ((dest == NULL && src == NULL) || n == 0)
		return (dest);
	d_move = (unsigned char *)dest;
	s_move = (const unsigned char *)src;
	if (dest > src)
	{
		i = 0;
		while (i < n)
		{
			d_move[n - i - 1] = s_move[n - i - 1];
			i++;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
