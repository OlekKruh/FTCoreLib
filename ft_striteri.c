/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 17:11:59 by okruhlia          #+#    #+#             */
/*   Updated: 2025/10/05 17:34:51 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	id;

	id = 0;
	while (s[id])
	{
		(*f)(id, &s[id]);
		id++;
	}
}