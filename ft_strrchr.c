/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 14:43:28 by okruhlia          #+#    #+#             */
/*   Updated: 2025/09/28 14:43:36 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	size_t	id;
	char	*res;

	id = 0;
	res = NULL;
	while (str[id] != '\0')
	{
		if (str[id] == (char)ch)
		{
			res = (char *)str + id;
		}
		id++;
	}
	if (ch == '\0')
		return ((char *)(str + id));
	return (res);
}
