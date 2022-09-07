/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanotomoki <asanotomoki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:26:45 by asanotomoki       #+#    #+#             */
/*   Updated: 2022/03/11 06:39:02 by asanotomoki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	i;
	size_t	len;

	if (s == NULL)
		return (NULL);
	if (f == NULL)
		return (ft_strdup(s));
	len = ft_strlen(s);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = f((unsigned int)i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
