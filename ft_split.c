/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 19:07:09 by okruhlia          #+#    #+#             */
/*   Updated: 2025/10/04 01:58:42 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(const char *src, char spl)
{
	size_t		res_id;
	char		**result;
	const char	*spl_ptr;
	const char	*start;

	if (!src || *src == '\0')
		return (NULL);
	res_id = 0;
	start = src;
	result = malloc((ft_strlen(src) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (*start)
	{
		spl_ptr = ft_strchr(start, spl);
		if (spl_ptr == NULL)
			spl_ptr = start + ft_strlen(start);
		if (spl_ptr - start > 0)
			result[res_id++] = ft_substr(start, 0, spl_ptr - start);
		if (*spl_ptr != '\0')
			start = spl_ptr + 1;
		else
			start = spl_ptr;
	}
	result[res_id] = NULL;
	return (result);
}
//	if (res_id == 0)
//		return (free(result), NULL);
