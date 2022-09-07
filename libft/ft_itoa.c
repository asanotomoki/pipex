/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 03:00:26 by asanotomoki       #+#    #+#             */
/*   Updated: 2022/07/25 15:41:09 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_loop(int n, char *num, int index)
{
	if (n == 0)
	{
		return ;
	}
	ft_loop (n / 10, num, --index);
	num[index] = (n % 10) * -1 + '0';
}

char	*ft_itoa(int n)
{
	char	*num;
	size_t	digit;

	digit = ft_get_digit(n);
	if (n < 0)
		digit += 1;
	else if (n == 0)
		return (ft_strdup("0"));
	num = ft_calloc(digit + 1, sizeof(char));
	if (num == NULL)
		return (NULL);
	if (n < 0)
		num[0] = '-';
	else
		n *= -1;
	ft_loop(n, num, digit);
	return (num);
}
