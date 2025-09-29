/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 20:31:07 by okruhlia          #+#    #+#             */
/*   Updated: 2025/09/29 19:57:11 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	space_to_copy;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	space_to_copy = size - dst_len - 1;
	if (dst_len >= size)
		return (size + src_len);
	if (space_to_copy >= src_len)
	{
		ft_memcpy(dst + dst_len, src, src_len);
		dst[dst_len + src_len] = '\0';
	}
	else
	{
		ft_memcpy(dst + dst_len, src, space_to_copy);
		dst[dst_len + space_to_copy] = '\0';
	}
	return (dst_len + src_len);
}
