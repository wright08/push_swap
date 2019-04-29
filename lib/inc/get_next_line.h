/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwright <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 21:24:06 by rwright           #+#    #+#             */
/*   Updated: 2019/04/24 14:50:50 by rwright          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include "vector.h"

# define BUFF_SIZE 4096

struct	s_file
{
	int		fd;
	char	*thread;
	int		len;
};
typedef struct s_file	t_file;

int		get_next_line(const int fd, char **line);

#endif
