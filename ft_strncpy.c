/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 15:40:46 by okruhlia          #+#    #+#             */
/*   Updated: 2025/09/26 15:40:54 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t	id;

	id = 0;
	while (id < len && src[id] != '\0')
	{
		dest[id] = src[id];
		id++;
	}
	while (id < len)
	{
		dest[id] = '\0';
		id++;
	}
	return (dest);
}
