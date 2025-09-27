/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 20:16:28 by okruhlia          #+#    #+#             */
/*   Updated: 2025/09/27 20:18:04 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t len)
{
	size_t			id;
	unsigned char	*arg1;
	unsigned char	*arg2;

	id = 0;
	arg1 = (unsigned char *)str1;
	arg2 = (unsigned char *)str2;
	while (id <= len)
	{
		if (arg1[id] != arg2[id])
			return (arg1[id] - arg2[id]);
		id++;
	}
	return (0);
}
