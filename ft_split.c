#include "push_swap.h"

int	delim_count(char *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

char	*get_the_word(char *str, int *index, char c)
{
	int		start;
	char	*word;
	int		count;
	int		i;

	start = *index;
	count = 0;
	while (str[start] && str[start] == c)
		start++;
	*index = start;
	while (str[*index] && str[*index] != c)
	{
		(*index)++;
		count++;
	}
	word = malloc(sizeof(char) * (count + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < count)
	{
		word[i] = str[start + i];
		i++;
	}
	return (word[i] = '\0', word);
}

char	**ft_split(char *str, char separator)
{
	char	**new_str;
	int		word_count;
	int		index;
	int		i;

	word_count = delim_count(str, separator);
	new_str = malloc(sizeof(char *) * (word_count + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	index = 0;
	while (i < word_count)
	{
		new_str[i] = get_the_word(str, &index, separator);
		if (!new_str[i])
		{
			while (i > 0)
				free(new_str[--i]);
			return (free(new_str), NULL);
		}
		i++;
	}
	return (new_str[i] = NULL, new_str);
}
