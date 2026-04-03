#include <stdio.h>
#include <stdlib.h>

int	*f_range(int min, int max)
{
	int	i;
	int	*table;

	if (min >= max)
		return (NULL);
	table = malloc(sizeof(int) * (max - min));
	i = 0;
	while (min < max)
		table[i++] = min++;
	return (table);
}

int	main()
{
	int *str;
	int i = 0;
	str = f_range(0,5);

	while (str[i] < 42)
	{
		printf("%d",str[i]);
		i++;
	}
	printf("\n");
}

