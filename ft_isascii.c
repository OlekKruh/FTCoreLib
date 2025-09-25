#include "libft.h"

int	ft_isascii(const int ch)
{
	if (0 <= ch && ch<= 127)
		return (1);
	return (0);
}