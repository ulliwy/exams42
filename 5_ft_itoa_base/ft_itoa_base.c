#include <stdlib.h>

int		calc_len(int value, int base)
{
	int len = 0;
	unsigned int uv;

	uv = (unsigned int)value;
	if (value < 0 && base == 10)
	{
		uv = -uv;
		len++;
	}
	if (value < 0 && base != 10)
		uv = -value;
	if (value == 0)
		return (len + 1);
	while (uv > 0)
	{
		uv = uv / base;
		len++;
	}
	return (len);
}

char    *ft_itoa_base(int value, int base)
{
	char hex[17] = "0123456789ABCDEF";
	char *str;
	int len = 0;
	int i = 0;

	len = calc_len(value, base);
	str = (char *)malloc(len + 1);
	unsigned int	uvalue;
	uvalue = value;
	if (value < 0 && base == 10)
	{
		str[i] = '-';
		i++;
		uvalue = -value;
	}
	if (value < 0 && base != 10)
		uvalue = -value;
	if (!uvalue)
	{
		str[i] = '0';
		str[i + 1] = '\0';
		return (str);
	}
	int j = len - 1;
	while (j >= i && uvalue)
	{
		str[j] = hex[uvalue % base];
		uvalue = uvalue / base;
		j--;
	}
	str[len] = '\0';
	return (str);
}
