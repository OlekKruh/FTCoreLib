#include "ft_lib.h"

void	*ft_calloc(size_t quant, size_t len)
{
	void			*memo;
	size_t	size;
	if(quant == 0 || len == 0)
		return (NULL);

	if(quant > SIZE_MAX / len)
		return (NULL);

	size = quant * len;
	memo = malloc(size);

	if(!memo)
		return (NULL);
	else
	{
		ft_bzero(memo, size);
		return (memo);
	}
}
