#include "libft.h"

int	ft_strlen(const char *src)
{
	size_t	id;

	id = 0;
	while (src[id] != '\0')
		id++;
	return (id);
}