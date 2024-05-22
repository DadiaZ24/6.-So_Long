/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:23:56 by ddias-fe          #+#    #+#             */
/*   Updated: 2024/04/11 15:23:56 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	checksplits(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	j = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			j = 0;
		else if (s[i] != c && j == 0)
		{
			count++;
			j = 1;
		}
		i++;
	}
	return (count);
}

static int	checksize(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char	*allocstr(char const *s, char c)
{
	size_t	i;
	size_t	size;
	char	*str;

	i = 0;
	size = checksize(s, c);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (i < size)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	size;
	size_t	num_splits;
	char	**split;

	i = -1;
	j = 0;
	if (s == NULL)
		return (NULL);
	num_splits = checksplits(s, c);
	split = (char **)malloc((num_splits + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	while (num_splits > ++i)
	{
		while (s[j] == c)
			j++;
		size = checksize(s + j, c);
		split[i] = allocstr(s + j, c);
		if (split[i] == NULL)
		{
			while (i > 0)
				free(split[--i]);
			free(split);
			return (NULL);
		}
		j += size;
	}
	split[i] = NULL;
	return (split);
}

/* int	main()
{
	int	i;
	char	**split;

	i = 0;
	split = ft_split(" Tripouille", ' ');
	while (i < 10)
	{
		//printf("SPLIT[%d] = [%s]\n", i, split[i]);
		i++;
	}
} */