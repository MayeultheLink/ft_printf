/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <mde-la-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 17:17:37 by mde-la-s          #+#    #+#             */
/*   Updated: 2020/12/18 14:19:18 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*d)(void *))
{
	t_list	*lst_f;
	t_list	*lst_tmp;

	if (!f || !lst)
		return (NULL);
	if (!(lst_f = ft_lstnew(f(lst->content))))
	{
		ft_lstclear(&lst, d);
		return (NULL);
	}
	lst = lst->next;
	while (lst)
	{
		if (!(lst_tmp = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&lst, d);
			ft_lstclear(&lst_f, d);
			return (NULL);
		}
		ft_lstadd_back(&lst_f, lst_tmp);
		lst = lst->next;
	}
	return (lst_f);
}
