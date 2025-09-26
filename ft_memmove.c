/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 10:11:01 by okruhlia          #+#    #+#             */
/*   Updated: 2025/09/26 14:07:59 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	if (!dest || !src)
		return (NULL);
	if (dest > src && (char *)src + len > (char *)dest)
	{
		while (len > 0)
		{
			len--;
			((unsigned char *) dest)[len] = ((unsigned char *) src)[len];
		}
	}
	else
	{
		return (ft_memcpy(dest, src, len));
	}
	return (0);
}
