#include "libft.h"

int	ft_isalpha(const int ch)
{
	if (('a' <= ch &&  ch <= 'z') || ('A' <= ch && ch <= 'Z'))
		return (1);
	return (0);
}