/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:13:33 by okruhlia          #+#    #+#             */
/*   Updated: 2025/10/10 11:18:43 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*corent_pos;
	int		count;

	corent_pos = lst;
	count = 0;
	while (corent_pos != NULL)
	{
		count++;
		corent_pos = corent_pos->next;
	}
	return (count);
}
