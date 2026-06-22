/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:58:55 by adraji            #+#    #+#             */
/*   Updated: 2025/12/30 11:58:53 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parsing.h"

static t_array	*ft_create_array_struct(char *joined)
{
	int		i;
	t_array	*array;

	i = 0;
	array = ft_safe_malloc(sizeof(t_array));
	array->size = 0;
	while (joined[i])
	{
		while (joined[i] && joined[i] == ' ')
			i++;
		if (joined[i])
			array->size++;
		while (joined[i] && (ft_is_signe(joined[i]) || ft_isdigit(joined[i])))
			i++;
	}
	if (array->size <= 0)
		exit(ft_cleanup_memory(ft_error_staus));
	if (array->size < 2)
		exit(ft_cleanup_memory(NULL));
	array->values = ft_safe_malloc(sizeof(int) * array->size);
	return (array);
}

static t_array	*ft_fill_array(char *joined)
{
	int			i;
	int			j;
	t_array		*array;

	i = 0;
	j = 0;
	array = ft_create_array_struct(joined);
	while (joined[i])
	{
		while (joined[i] == ' ')
			i++;
		if (!joined[i])
			break ;
		array->values[j++] = ft_atoi_ilimit(&joined[i]);
		if (ft_is_signe(joined[i]))
			i++;
		while (ft_isdigit(joined[i]))
			i++;
	}
	return (array);
}

static void	ft_check_duplicates(t_array *array)
{
	int	i;
	int	*tmp;

	i = 0;
	tmp = ft_safe_malloc(sizeof(int) * array->size);
	ft_memcpy(tmp, array->values, sizeof(int) * array->size);
	ft_quick_sort(tmp, 0, array->size - 1);
	while (i < array->size - 1)
	{
		if (tmp[i] == tmp[i + 1])
			exit(ft_cleanup_memory(ft_error_staus));
		i++;
	}
}

t_array	ft_parsing(int size, char **strs)
{
	t_array	res;
	t_array	*tmp;
	char	*joined;

	joined = ft_strsjoin_check(size, strs);
	tmp = ft_fill_array(joined);
	ft_check_duplicates(tmp);
	res.size = tmp->size;
	res.values = malloc(sizeof(int) * res.size);
	if (!res.values)
		exit(ft_cleanup_memory(ft_allocation_staus));
	ft_memcpy(res.values, tmp->values, sizeof(int) * res.size);
	ft_cleanup_memory(NULL);
	return (res);
}
