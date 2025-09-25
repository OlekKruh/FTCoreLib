#include "libft.h"

int	ft_isprint(const int ch)
{
	if (32 <= ch && ch <= 126)
		return (1);
	return (0);
}