/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwright <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 10:49:00 by rwright           #+#    #+#             */
/*   Updated: 2019/01/21 22:15:54 by rwright          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dst, const char *src)
{
	char *start;

	start = dst;
	while (*dst)
		dst++;
	while (*src)
		*(dst++) = *(src++);
	*dst = '\0';
	return (start);
}
