#include <stdio.h>
#include <stdlib.h>

int	f_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*f_strdup(char *src)
{
	int		i;
	char	*dest;

	if (!src)
		return (NULL);
	dest = malloc(f_strlen(src) * sizeof(char) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int main()
{
	char src[] = "This is a test";
//	char src1[] = "\0";
	char *dest = f_strdup(src);
	printf("%s\n", dest);
}

