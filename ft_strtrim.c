/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 21:09:49 by okruhlia          #+#    #+#             */
/*   Updated: 2025/09/30 21:09:58 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_id;
	size_t	s1_len;
	char	*res;

	if (!s1 || !set)
		return (ft_strdup(""));
	s1_len = ft_strlen(s1);
	s1_id = 0;
	while (s1[s1_id] && ft_strchr(set, (int)s1[s1_id]))
		s1_id++;
	while (s1_len > s1_id && ft_strchr(set, s1[s1_len - 1]))
		s1_len--;
	if (s1_len <= s1_id)
		return (ft_strdup(""));
	res = (char *)malloc(s1_len - s1_id + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1 + s1_id, s1_len - s1_id + 1);
	return (res);
}
