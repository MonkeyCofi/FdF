/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:52:28 by pipolint          #+#    #+#             */
/*   Updated: 2023/11/12 13:51:29 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_separator(char *sep, char c)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (c == sep[i])
			return (1);
		i++;
	}
	return (0);
}

static int	count_words(char const *s, char *sep)
{
	int	words;
	int	letters;
	int	i;

	i = 0;
	words = 0;
	letters = 0;
	while (s[i])
	{
		if (!is_separator(sep, s[i]))
			letters++;
		else if (is_separator(sep, s[i]) && letters)
		{
			letters = 0;
			words++;
		}
		if (s[i + 1] == '\0' && !is_separator(sep, s[i]))
			words++;
		i++;
	}
	return (words);
}

static int	get_length(const char *s, char *sep)
{
	int	length;

	length = 0;
	while (*s != '\0' && !is_separator(sep, *s))
	{
		length++;
		s++;
	}
	return (length);
}

static void	add_words(char **words, char *s, char *sep)
{
	char	*word;
	int		current_word;
	int		i;

	current_word = 0;
	while (*s)
	{
		i = 0;
		if (!is_separator(sep, *s))
		{
			word = (char *)malloc(sizeof(char) * (get_length(s, sep) + 1));
			if (!word)
				return ;
			while (*s && !is_separator(sep, *s))
				word[i++] = *s++;
			word[i] = '\0';
			words[current_word++] = ft_strdup(word);
			free(word);
		}
		else
			s++;
	}
	words[current_word] = 0;
}

char	**ft_split(char const *s, char *sep)
{
	char	**words;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, sep);
	words = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!words)
		return (NULL);
	add_words(words, (char *)s, sep);
	return (words);
}
