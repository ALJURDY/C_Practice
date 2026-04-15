#include <stdlib.h>
#include <stdio.h>

int	check_base(char *str)
{
	int	i;
	int	j;

	if (!str || !str[0] || !str[1])
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == 32
			|| (str[i] >= 9 && str[i] <= 13))
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	count_num(int num, int base_len)
{
	int	len;

	len = 1;
	while (num >= base_len)
	{
		num = num / base_len;
		len++;
	}
	return (len);
}

void	get_result(int i, long num, char *base, char *res)
{
	int	len;

	len = 0;
	while (base[len])
		len++;
	while (num > 0)
	{
		res[i] = base[num % len];
		num = num / len;
		i--;
	}
}

int	ctov(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*itoa_base(int num, char *base)
{
	int		len;
	int		base_len;
	int		is_negative;
	char	*result;

	base_len = check_base(base);
	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}
	len = count_num(num, base_len);
	if (is_negative)
		len++;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (num == 0)
		result[--len] = base[0];
	while (num > 0)
	{
		result[--len] = base[num % base_len];
		num /= base_len;
	}
	if (is_negative)
		result[0] = '-';
	return (result);
}
