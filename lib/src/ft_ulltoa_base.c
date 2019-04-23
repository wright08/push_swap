/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwright <rwright@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 10:15:07 by rwright           #+#    #+#             */
/*   Updated: 2019/03/07 10:15:16 by rwright          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(unsigned long long n, int base)
{
	int len;

	len = 1;
	while ((n /= base))
		len++;
	return (len);
}

char		*ft_ulltoa_base(unsigned long long n, int base)
{
	char	*ret;
	int		len;
	char	*base_digits;

	if (base < 17)
		base_digits = "0123456789abcdef";
	else
	{
		base_digits = "0123456789ABCDEF";
		base = 16;
	}
	len = num_len(n, base);
	if ((ret = ft_strnew(len)))
	{
		while (len--)
		{
			ret[len] = base_digits[n % base];
			n /= base;
		}
	}
	return (ret);
}
