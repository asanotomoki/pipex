/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 23:29:51 by asanotomoki       #+#    #+#             */
/*   Updated: 2022/06/06 22:20:49 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*t;
	size_t	length;

	length = ft_strlen(s1);
	t = (char *)malloc(sizeof(char) * (length + 1));
	if (t == NULL)
		return (NULL);
	ft_strlcpy(t, s1, length + 1);
	return (t);
}
