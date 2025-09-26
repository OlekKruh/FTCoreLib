/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:37:02 by okruhlia          #+#    #+#             */
/*   Updated: 2025/09/26 14:09:28 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		id;
	size_t	len;
	char	*src_copy;

	id = 0;
	len = ft_strlen(src);
	src_copy = malloc(len + 1);
	if (!src_copy)
		return (NULL);
	while (src[id] != '\0')
	{
		src_copy[id] = src[id];
		id++;
	}
	src_copy[id] = '\0';
	return (src_copy);
}
