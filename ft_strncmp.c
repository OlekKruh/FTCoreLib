/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 19:14:03 by okruhlia          #+#    #+#             */
/*   Updated: 2025/10/02 19:27:05 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t len)
{
	size_t	id;

	id = 0;
	if (!len)
		return (0);
	while (id < len && (str1[id] || str2[id]))
	{
		if (str1[id] != str2[id])
			return ((unsigned char)str1[id] - (unsigned char)str2[id]);
		id++;
	}
	return (0);
}
