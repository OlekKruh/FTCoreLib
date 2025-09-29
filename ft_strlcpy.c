/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:18:24 by okruhlia          #+#    #+#             */
/*   Updated: 2025/09/29 19:55:02 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	if (size - 1 < src_len)
	{
		ft_memcpy (dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	else
	{
		ft_memcpy(dst, src, src_len);
		dst[src_len] = '\0';
	}
	return (src_len);
}
