/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 05:40:39 by asanotomoki       #+#    #+#             */
/*   Updated: 2022/05/20 21:11:42 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_content;
	t_list	*new_list;

	new_list = NULL;
	while (lst != NULL)
	{
		if (f != NULL)
			new_content = ft_lstnew(f(lst->content));
		else
			new_content = ft_lstnew(lst->content);
		if (new_content == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_content);
		lst = lst->next;
	}
	return (new_list);
}

//aa->bb->cc->dd
//AA->BB->CC->DD
