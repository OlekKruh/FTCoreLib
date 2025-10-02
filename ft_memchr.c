/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:33:06 by okruhlia          #+#    #+#             */
/*   Updated: 2025/09/27 17:40:32 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int arg, size_t len)
{
	size_t			id;
	unsigned char	*ptr;
	unsigned char	ch;

	id = 0;
	ptr = (unsigned char *)src;
	ch = (unsigned char)arg;
	while (id < len)
	{
		if (ptr[id] == ch)
			return ((void *)&ptr[id]);
		id++;
	}
	return (NULL);
}
