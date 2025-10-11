/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:22:10 by okruhlia          #+#    #+#             */
/*   Updated: 2025/10/10 11:27:14 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*corent_pos;

	if (!lst)
		return (NULL);
	corent_pos = lst;
	while (corent_pos -> next)
		corent_pos = corent_pos -> next;
	return (corent_pos);
}
