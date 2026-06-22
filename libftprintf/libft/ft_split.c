/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 07:47:41 by adraji            #+#    #+#             */
/*   Updated: 2025/12/12 07:47:41 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_cleanup_memory(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	return (free(tab), NULL);
}

static size_t	ft_strcount(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	**ft_strfill(char **tab, const char *s, char c, size_t word_count)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (i < word_count)
	{
		while (s[j] && s[j] == c)
			j++;
		start = j;
		while (s[j] && s[j] != c)
			j++;
		tab[i] = ft_substr(s, start, j - start);
		if (!tab[i])
			return (ft_cleanup_memory(tab));
		i++;
	}
	return (tab);
}

char	**ft_split(const char *s, char c)
{
	char	**tab;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = ft_strcount(s, c);
	tab = ft_calloc(word_count + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	return (ft_strfill(tab, s, c, word_count));
}
