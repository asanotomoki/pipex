/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 21:18:42 by asanotomoki       #+#    #+#             */
/*   Updated: 2022/09/13 01:52:35 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
size_t	ft_get_size(char const *s, char c);
char	**ft_free_all(char **res, size_t size);
char	**ft_s_cpy(char **res, char const	*s, char c, size_t res_size);

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	res_s;

	if (s == NULL)
		return (NULL);
	res_s = ft_get_size(s, c);
	res = (char **)malloc((res_s + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	return (ft_s_cpy(res, s, c, res_s));
}

char	**ft_s_cpy(char **res, char const *s, char c, size_t res_size)
{
	size_t	index;
	size_t	len;
	size_t	i;

	index = 0;
	i = 0;
	while (s[i] != '\0' && index < res_size)
	{
		len = 0;
		while (s[i] != '\0' && s[i] == c)
			i++;
		while (s[i + len] != '\0' && s[i + len] != c)
			len++;
		if (len != 0)
		{
			res[index] = ft_substr(s, i, len);
			if (res[index] == NULL)
				return (ft_free_all(&res[index], index));
			index++;
		}
		i += len;
	}
	res[index] = NULL;
	return (res);
}

char	**ft_free_all(char **res, size_t size)
{
	while (size)
	{
		free(res[size]);
		size --;
	}
	free(res);
	return (NULL);
}

size_t	ft_get_size(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
		while (s[i] != '\0' && s[i] == c)
			i++;
	}
	return (count);
}
