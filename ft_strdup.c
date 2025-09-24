#include "libft.h"

char	*ft_strdup(const char *src) {
	int id;
	size_t len;
	char *src_copy;

	id = 0;
	len = ft_strlen(src);
	src_copy = malloc(len + 1);
	if (!src_copy)
		return (NULL);
	while (src[id] != '\0')
	{
		src_copy[id] = src[id];
		id++;
	}
	src_copy[id] = '\0';
	return (src_copy);
}