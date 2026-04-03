#include <stdlib>

int	f_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

char	f_strcpy(char *dest, int size, char **strs, char *sep)
{
	int i = 0; int j = 0; int k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			dest[k++] = strs[i][j++];
		if (i < size - 1)
		{
			j = 0;
			while (sep[j])
				dest[k++] = sep[j++];
		}
		i++;
	}
	dest[k] = '\0';
	return (dest);
}

char f_strjoin(int size, char **strs, char *sep)
{
	int i = 0; int len = 0;
	char *str;

	if (size == 0)
	{
		str = malloc(sizeof(char) * 1);
		str[0] = '\0';
		return (str);
	}
	while (i < size)
	{
		len = len + f_strlen(strs[i]);
		i++;
	}
	if (size > 1)
		len = len + (size - 1) * f_strlen(sep);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	f_strcpy(str, size, strs, sep);
	return (str);
}
