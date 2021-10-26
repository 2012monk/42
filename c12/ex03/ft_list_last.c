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

t_list	*ft_list_last(t_list *begin_list)
{
	if (!begin_list)
		return (begin_list);
	while (begin_list->next)
		begin_list = begin_list->next;
	return (begin_list);
}
#include "ft_list.h"
#include <stdio.h>
t_list *ft_list_push_strs(int size, t_list *list);
int main()
{
	char *l[] = {"1","2","#"};
	t_list *r;

	int i =-1;
	while (++i < 3)
	{
	r = malloc(sizeof(t_list));
	r -> data = l[i];
		r = r->next;
	}
	printf("%s", ft_list_last(r)->data);
}