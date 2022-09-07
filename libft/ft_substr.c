/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanotomoki <asanotomoki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 23:56:16 by asanotomoki       #+#    #+#             */
/*   Updated: 2022/03/09 01:17:45 by asanotomoki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub_str;

	i = ft_strlen(s);
	if (len + start > i)
	{
		if (i > start)
			len = i - start;
		else
			len = 0;
	}
	sub_str = (char *)malloc(sizeof(char) * (len + 1));
	if (sub_str == NULL)
		return (sub_str);
	ft_strlcpy(sub_str, &s[start], len + 1);
	return (sub_str);
}
