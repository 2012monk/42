/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:21:49 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/23 12:21:50 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*tmp;
	t_list	*head;

	head = begin_list;
	while (begin_list)
	{
		tmp = begin_list;
		begin_list = begin_list->next;
		free_fct(tmp->data);
		free(tmp);
	}
	free(head);
}

// #include "ft_list.h"
// #include <stdlib.h>
// #include <stdio.h>
// void	f(void *d)
// {
// 	printf("%s\n", d);

// }
// t_list	*ft_list_at(t_list *begin_list, unsigned int nbr);
// void	ft_list_reverse(t_list **begin_list);
// int	main()
// {
// 	t_list *list;
// 	t_list *tmp;
// 	char	*m[] = {"1","2","3","4","5"};

// 	list = malloc(sizeof(t_list *));
// 	tmp = list;
// 	tmp->data = m[0];
// 	for (int i=1;i<5;i++)
// 	{
// 		tmp->next = malloc(sizeof(t_list));
// 		tmp = tmp->next;
// 		tmp->data = m[i];
// 	}
// 	ft_list_clear(list, f);
// 	printf("===%d\n", list == NULL);
// 	while (list)
// 	{
// 		if (list)
// 			printf("%s", list->data);
// 	}
// }