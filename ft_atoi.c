#include <unistd.h>

int	ft_atoi(const char *src)
{
	int		id;
	int		sig;
	int		res;

	id = 0;
	sig = 1;
	res = 0;
	while (src[id] == 32 || (src[id] >= 9 && src[id] <= 13))
		id++;
	while (src[id] == '-' || src[id] == '+')
	{
		if (src[id] == '-')
			sig *= -1;
		id++;
	}
	while ('0' <= src[id] && src[id] <= '9')
	{
		res = res * 10 + src[id] - '0';
		id++;
	}
	return (sig * res);
}
