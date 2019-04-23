/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwright <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 20:47:24 by rwright           #+#    #+#             */
/*   Updated: 2019/03/07 16:33:15 by rwright          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char *str, unsigned int start, size_t len)
{
	char	*ret;

	if ((ret = ft_strnew(len)))
		ft_memcpy(ret, str + start, len);
	return (ret);
}
