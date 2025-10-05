/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 12:00:51 by okruhlia          #+#    #+#             */
/*   Updated: 2025/10/05 14:48:33 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	int_len(int fig);

char	*ft_itoa(int fig)
{
	char	*res;
	size_t	len;
	long	l_fig;

	l_fig = fig;
	len = int_len(l_fig) + 1;
	res = malloc(sizeof(char) * len);
	if (!res)
		return (NULL);
	res[--len] = '\0';
	if (l_fig < 0)
	{
		l_fig = -l_fig;
		res[0] = '-';
	}
	if (l_fig == 0)
		res[0] = '0';
	while (l_fig)
	{
		res[--len] = (l_fig % 10) + '0';
		l_fig /= 10;
	}
	return (res);
}

size_t	int_len(int fig)
{
	size_t	id;

	id = 0;
	if (fig == 0)
		return (1);
	if (fig == INT_MIN)
		return (11);
	if (fig == INT_MAX)
		return (10);
	if (fig < 0)
	{
		fig = -fig;
		id++;
	}
	while (fig)
	{
		fig /= 10;
		id++;
	}
	return (id);
}
