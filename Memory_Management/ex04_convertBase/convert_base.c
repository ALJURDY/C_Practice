#include <stdlib.h>
#include <stdio.h>

char	*itoa_base(int num, char *base);
int		ctov(char c, char *str);
int		check_base(char *str);

int	atoi_base(char *nbr, char *base)
{
	int	base_len;
	int	i;
	int	sign;
	int	result;

	base_len = check_base(base);
	if (!nbr || base_len == 0)
		return (0);
	i = 0;
	while (nbr[i] == 32 || (nbr[i] >= 9 && nbr[i] <= 13))
		i++;
	sign = 1;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			sign = -sign;
		i++;
	}
	result = 0;
	while (ctov(nbr[i], base) != -1)
	{
		result = result * base_len + ctov(nbr[i], base);
		i++;
	}
	return (sign * result);
}

char	*convert_base(char *nbr, char *base_from, char *base_to)
{
	int	i;

	if (check_base(base_from) == 0 || check_base(base_to) == 0)
		return (NULL);
	i = atoi_base(nbr, base_from);
	return (itoa_base(i, base_to));
}

int	main()
{
	char *result;
 	printf("source base is %d\n", check_base("01"));
	printf("distenation base is %d\n", check_base("0123456789ABCDEF"));
	result = convert_base("-1023827911", "0123456789ABCDEF", "01");
	printf("2A (hex) -> %s (binary)\n", result);
	free(result);
}

