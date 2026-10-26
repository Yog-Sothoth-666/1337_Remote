/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhaldou <ykhaldou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 13:32:53 by ykhaldou          #+#    #+#             */
/*   Updated: 2026/10/18 13:46:38 by ykhaldou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*nextptr;

	if (!lst || !del || !*lst)
		return ;
	current = *lst;
	while (lst)
	{
		nextptr = current->next;
		del(current->content);
		free(current);
		current = nextptr;
	}
	*lst = NULL;
}
