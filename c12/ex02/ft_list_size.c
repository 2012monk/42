/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:06:24 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/23 12:06:26 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	i;

	i = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}

// #include "ft_list.h"
// #include <stdio.h>
// t_list *ft_list_push_strs(int size, t_list *list);
// int main()
// {
// 	char *l[] = {"1","2","#"};
// 	t_list *r;
// 	t_list *ll;

// 	int i = 0;

// 	r = malloc(sizeof(t_list));
// 	r->data = l[0];
// 	ll = r;
// 	while (++i < 3)
// 	{
// 		r->next = malloc(sizeof(t_list));
// 		r ->next-> data = l[i];
// 		r = r->next;
// 	}
// 	r = ll;
// 	while (r)
// 	{
// 		printf("%s\n", r->data);
// 		r = r->next;
// 	}
// 	printf("%d", ft_list_size(ll));
// }