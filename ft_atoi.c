int	ft_atoi(const char *src)
{
	int		id;
	int		sign;
	int		res;
	int		sign_count;

	id = 0;
	sign = 1;
	res = 0;
	sign_count = 0;
	while (src[id] == 32 || (src[id] >= 9 && src[id] <= 13))
		id++;
	while (src[id] == '-' || src[id] == '+') {
		if (src[id] == '-')
			sign = -sign;
		sign_count++;
		id++;
	}
	if (sign_count > 1)
		return 0;
	while ('0' <= src[id] && src[id] <= '9')
	{
		res = res * 10 + src[id] - '0';
		id++;
	}
	return (sign * res);
}
