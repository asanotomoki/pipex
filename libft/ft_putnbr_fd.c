/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanotomoki <asanotomoki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:17:04 by asanotomoki       #+#    #+#             */
/*   Updated: 2022/03/12 00:29:18 by asanotomoki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_loop(int n, int fd)
{
	if (n == 0)
	{
		return ;
	}
	ft_putnbr_loop (n / 10, fd);
	ft_putchar_fd ((n % 10) * -1 + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	else if (n > 0)
		n *= -1;
	else
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	ft_putnbr_loop(n, fd);
}
