/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 03:20:54 by asanotomoki       #+#    #+#             */
/*   Updated: 2022/05/06 15:09:17 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	size_t			end;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_substr(s1, 0, ft_strlen(s1)));
	start = 0;
	while (s1[start] != '\0' && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while ((size_t)start <= end && ft_strchr(set, s1[end]))
		end--;
	end++;
	return (ft_substr(s1, start, end - (size_t)start));
}
