/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 07:49:10 by adraji            #+#    #+#             */
/*   Updated: 2025/12/12 07:49:10 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(const char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static size_t	ft_lentrim(const char *s1, const char *set)
{
	size_t	start_trim;
	size_t	end_trim;

	start_trim = 0;
	end_trim = ft_strlen(s1) - 1;
	while (s1[start_trim] && ft_isset(s1[start_trim], set))
		start_trim++;
	if (start_trim > end_trim)
		return (0);
	while (ft_isset(s1[end_trim], set))
		end_trim--;
	return ((end_trim - start_trim) + 1);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	len;
	char	*trim;

	if (!s1 || !set || !*set)
		return (ft_strdup(s1));
	i = 0;
	len = ft_lentrim(s1, set);
	if (!len)
		return (ft_strdup(""));
	trim = malloc(sizeof (char) * (len + 1));
	if (!trim)
		return (NULL);
	while (ft_isset(*s1, set))
		s1++;
	while (i < len)
		trim[i++] = *(s1++);
	trim[i] = '\0';
	return (trim);
}
