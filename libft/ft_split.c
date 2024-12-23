/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorlett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:38:59 by rcorlett          #+#    #+#             */
/*   Updated: 2024/10/28 09:47:03 by rcorlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (words);
}

static int	get_substring_length(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i])
	{
		i++;
		len++;
	}
	return (len);
}

static void	free_memory(char **arr, int j)
{
	while (--j >= 0)
		free(arr[j]);
	free(arr);
}

static char	*extract_substring(char const *s, int i, char c)
{
	char	*substring;
	int		substring_len;

	substring_len = get_substring_length(s, c, i);
	substring = ft_substr(s, i, substring_len);
	return (substring);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	int		i;
	int		j;
	char	**arr;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	arr = (char **)malloc((words + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	while (j < words)
	{
		while (s[i] == c)
			i++;
		arr[j] = extract_substring(s, i, c);
		if (!arr[j])
			return (free_memory(arr, j), NULL);
		i += get_substring_length(s, c, i);
		j++;
	}
	arr[j] = NULL;
	return (arr);
}

/*#include <stdio.h>
int main(void)
{
    char **result;
    result = ft_split("Renan Corlett Silva", ' ');
    printf("Word 1: %s\n", result[0]);
    printf("Word 2: %s\n", result[1]);
    printf("Word 3: %s\n", result[2]);
    return (0);
}*/
