/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:08:06 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/23 12:08:07 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_lase(t_list *begin_list)
{
	if (!*begin_list)
		return (begin_list);
	while (begin_list->next)
		begin_list = begin_list->next;
	return (begin_list);
}
