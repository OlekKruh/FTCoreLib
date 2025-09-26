/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:26:03 by okruhlia          #+#    #+#             */
/*   Updated: 2025/09/25 16:27:51 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(const int ch)
{
	if (ft_isalpha(ch) || ft_isdigit(ch))
		return (1);
	return (0);
}
