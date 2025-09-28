/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:45:07 by okruhlia          #+#    #+#             */
/*   Updated: 2025/09/28 17:51:47 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	size_t	id;

	id = 0;
	while (str[id] != '0')
	{
		if (str[id] == (char)ch)
			return ((char *)(str + id));
		id++;
	}
	if (ch == '\0')
		return ((char *)(str + id));
	return (NULL);
}
