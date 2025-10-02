/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 12:10:02 by okruhlia          #+#    #+#             */
/*   Updated: 2025/09/28 12:47:52 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	size_t	str_id;
	size_t	sub_id;

	str_id = 0;
	if (substr[0] == '\0' || str == substr)
		return ((char *)str);
	while (str_id < len && str[str_id])
	{
		sub_id = 0;
		while (str_id + sub_id < len
			&& str[str_id + sub_id]
			&& substr[sub_id]
			&& str[str_id + sub_id] == substr[sub_id])
		{
			sub_id++;
		}
		if (substr[sub_id] == '\0')
			return ((char *)(str + str_id));
		str_id++;
	}
	return (NULL);
}
