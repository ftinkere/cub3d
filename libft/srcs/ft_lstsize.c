/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftinkere <ftinkere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 21:50:20 by ftinkere          #+#    #+#             */
/*   Updated: 2020/11/03 21:53:14 by ftinkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stddef.h>

int	ft_lstsize(t_list *lst)
{
	int	res;

	if (lst == NULL)
		return (0);
	res = 1;
	while (lst->next)
	{
		res++;
		lst = lst->next;
	}
	return (res);
}
