#include "ft_lib.h"

void	*ft_memset(void *dest, int ch, size_t len)
{
	unsigned char *ptr;
	ptr = (unsigned char *) dest;

	while(len > 0)
	{
		*ptr = ch;
		ptr++;
		len--;
	}
	return (dest);
}