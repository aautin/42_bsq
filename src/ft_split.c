/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsiao <yhsiao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:33:28 by yhsiao            #+#    #+#             */
/*   Updated: 2023/07/19 10:55:55 by yhsiao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!is_charset(str[i], charset))
		{
			count++;
			while (str[i] && !is_charset(str[i], charset))
				i++;
		}
		i++;
	}
	return (count);
}

char	*str_slice(char *str, char *charset, int *ptr)
{
	int		word_start;
	int		i;
	char	*slice;

	while (is_charset(str[*ptr], charset))
		(*ptr)++;
	word_start = *ptr;
	while (!is_charset(str[*ptr], charset) && str[*ptr])
		(*ptr)++;
	slice = (char *)malloc((*ptr - word_start + 1) * sizeof(char));
	if (!slice)
		return (NULL);
	i = 0;
	while (i + word_start < *ptr)
	{
		slice[i] = str[i + word_start];
		i++;
	}
	slice[i] = '\0';
	return (slice);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		ptr;
	int		word_count;
	char	**str_arr;

	word_count = count_word(str, charset);
	str_arr = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!str_arr)
		return (NULL);
	str_arr[word_count] = 0;
	ptr = 0;
	i = -1;
	while (++i < word_count)
		str_arr[i] = str_slice(str, charset, &ptr);
	return (str_arr);
}
