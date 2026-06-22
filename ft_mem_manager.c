/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 16:37:55 by adraji            #+#    #+#             */
/*   Updated: 2025/12/24 16:38:24 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static t_list	**ft_get_mem_manager(void)
{
	static t_list	*mem_list;

	return (&mem_list);
}

void	ft_free_content(void *content)
{
	free(content);
}

t_bool	ft_cleanup_memory(t_bool (*error_handler)(void))
{
	t_list	**mem_head;

	mem_head = ft_get_mem_manager();
	ft_lstclear(mem_head, ft_free_content);
	*mem_head = NULL;
	if (!error_handler || !error_handler())
		return (SUCCESS);
	return (FAILED);
}

void	*ft_safe_malloc(size_t size)
{
	void	*new_ptr;

	new_ptr = malloc(size);
	if (!new_ptr)
		exit(ft_cleanup_memory(ft_handle_alloc_error));
	ft_lstadd_back(ft_get_mem_manager(), ft_lstnew(new_ptr));
	return (new_ptr);
}
