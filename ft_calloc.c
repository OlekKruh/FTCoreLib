/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:19:47 by okruhlia          #+#    #+#             */
/*   Updated: 2025/10/09 21:22:16 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t quant, size_t len)
{
	void	*memo;
	size_t	size;

	if (quant == 0 || len == 0)
		return (malloc(0));
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
