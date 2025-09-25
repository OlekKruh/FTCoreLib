#include "libft.h"

int	ft_isdigit(const int dig)
{
	if ('0' <= dig && dig <= '9')
		return (1);
	return (0);
}