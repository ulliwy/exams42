int		max(int* tab, unsigned int len)
{
	int					max_v;
	unsigned int		i;

	if (len == 0)
		return (0);
	i = 1;
	max_v = tab[0];
	while (i < len)
	{
		if (tab[i] > max_v)
			max_v = tab[i];
		i++;
	}
	return (max_v);
}