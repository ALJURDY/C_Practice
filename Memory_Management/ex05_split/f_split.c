#include <stdlib.h>
#include <stdio.h>

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	word_len(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !is_sep(str[i], charset))
		i++;
	return (i);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!is_sep(str[i], charset))
		{
			count++;
			while (str[i] && !is_sep(str[i], charset))
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	*f_strcpy(char *src, char *charset)
{
	int	i;
	int	len;
	char	*dest;

	i = 0;
	len = word_len(src, charset);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**f_split(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab = malloc(sizeof(char *) * (count_word(str, charset) + 1));
	if (!tab)
		return (NULL);
	while (str[i])
	{
		if (!is_sep(str[i], charset))
		{
			tab[j++] = f_strcpy(&str[i], charset);
			while (str[i] && !is_sep(str[i], charset))
				i++;
		}
		else
			i++;
	}
	tab[j] = NULL;
	return (tab);
}

int	main()
{
	int i = 0;
	char *charset = ", .";
	char *tab = "Hello world!, Hello There!";
	char **res = f_split(tab, charset);
	while (res[i])
	{
		printf("%s\n", res[i]);
		i++;
	}
}

