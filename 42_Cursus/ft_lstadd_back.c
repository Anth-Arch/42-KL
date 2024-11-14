/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 23:06:26 by shkok             #+#    #+#             */
/*   Updated: 2024/11/14 23:15:16 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
	int	*last_node;

	if(!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last_node = ft_lstlast(*lst);
		if(last_node)
			new->content = last_node;
	}
}