#include <stdlib.h>

int	f_ultimate_range(int **range, int min, int max)

{
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc(sizeof(int) * (max - min));
	if (!range)
		return (-1);
	i = 0;
	while (min < max)
		(*range)[i++] = min++;
	return (i);
}

#include <stdio.h>
int main()
{
	int min = 0; int max = 10; int len = max - min; 
	int **range = malloc(sizeof(int*));
	int result = f_ultimate_range(range, min, max);
	printf("ret: %d\n", result);
	int i = 0;
	while (i < len)
	printf("%d, ", range[0][i++]);
	free(range[0]); free(range);
}

