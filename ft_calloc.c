/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:19:47 by okruhlia          #+#    #+#             */
/*   Updated: 2025/09/26 13:20:15 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t quant, size_t len)
{
	void	*memo;
	size_t	size;

	if (quant == 0 || len == 0)
		return (NULL);
	if (quant > SIZE_MAX / len)
		return (NULL);
	size = quant * len;
	memo = malloc(size);
	if (!memo)
		return (NULL);
	else
	{
		ft_bzero(memo, size);
		return (memo);
	}
}
