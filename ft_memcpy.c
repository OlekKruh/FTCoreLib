#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t id;

	id = 0;
	while (id < len)
	{
		((unsigned char *)dest)[id] = ((unsigned char *)src)[id];
		id++;
	}
	return (dest);
}