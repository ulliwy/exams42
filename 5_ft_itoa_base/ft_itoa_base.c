#include <stdlib.h>

int		calc_size(int value, int base)
{
	int		size;
	long	v;

	if (value < 0 && base == 10)
	{
		size = 1;
		v = -value;
	}
	else
	{
		size = 0;
		v = value;
	}
	if (value == 0)
		size++;
	while (v)
	{
		size++;
		v = v / base;
	}
	return (size);
}

int		ft_strlen(char *str)
{
	int len = 0;

	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

char	*rev(char *str)
{
	int		l;
	int		r;
	char	temp;

	r = ft_strlen(str) - 1;
	l = 0;
	while (l < r)
	{
		temp = str[l];
		str[l] = str[r];
		str[r] = temp;
		l++;
		r--;
	}
	return (str);
}

char    *ft_itoa_base(int value, int base)
{
	int		size;
	char	*str;
	int		neg;
	int		i;
	char	al[17] = "0123456789ABCDEF";
	long	v;

	if (base < 2 || base > 16)
		return (NULL);
	size = calc_size(value, base);
	//printf("%d\n", size);
	str = (char *)malloc(size + 1);
	neg = 0;
	v = value;
	if (v < 0)
	{
		v = -v;
		if (base == 10)
			neg = 1;
	}
	i = 0;
	if (value == 0)
	{
		str[i] = '0';
		i++;
	}
	while (v)
	{
		str[i] = al[v % base];
		v = v / base;
		i++;
	}
	if (neg)
	{
		str[i] = '-';
		i++;
	}
	str[i] = '\0';
	return (rev(str));
}
