/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwright <rwright@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 17:50:34 by rwright           #+#    #+#             */
/*   Updated: 2019/02/27 17:53:45 by rwright          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_pow(int base, int exponent)
{
	long ret;

	if (exponent == 0)
		return (1);
	ret = base;
	while (--exponent)
		ret *= base;
	return (ret);
}
