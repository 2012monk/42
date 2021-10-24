/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 11:45:22 by jonkim            #+#    #+#             */
/*   Updated: 2021/10/24 11:45:46 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"rush02.h"

char	**g_unique_map;
int		ft_fill_2num_map(void);
int		ft_fill_3num_map(void);

char    *ft_strcat(char *dest, char *src)  // 빈칸을 넣어주고 뒤에 이어붙이는 함수
{
    int i;
    int j;

    if (!src)
        return (NULL);
    i = ft_strlen(dest);
    j = 0;
    if (i != 0)
    {
        dest[i] = ' ';
        i++;
    }
    while (src[j] != 0)
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = 0;
    return (dest);
}

char    *get_t_map_value(int n)  // n 을 key 값으로 하는 g_number_map의 value를 가져오는 함수 
{
    int i;

    i = 0;
    while (g_number_map[i] != NULL)
    {
        if (g_number_map[i]->num == n)
            return (g_number_map[i]->value);
        i++;
    }
    return (NULL);
}

char    *ft_malloc_map(char *str1, char *str2, char *str3) // unique_map의 문자열들을 동적으로 할당해주는 함수
{
    int i;
    int len;
    char    *str;

    i = 0;
    len = 0;
    if (str1)
        len = ft_strlen(str1);
    if (str2)
        len += ft_strlen(str2) + 1;
    if (str3)
        len += ft_strlen(str3) + 1;
    if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
        {
                write(1, "memory allocation fail!" , 23);
                return (NULL);
        }
    while (i < len + 1)
    {
        str[i++] = 0;
    }
    return (str);
}

int fill_char_map(void)
{
    int i;

    i = 0;
    if(!(g_unique_map = (char **)malloc(1001 * sizeof(char *))))
    {
        write(1, "memory allocation error",23);
        return (-1);
    }
    while (i <= 100)
    {
        if (i < 20)
        {        
            g_unique_map[i] = ft_malloc_map(get_t_map_value(i), 0, 0);
            ft_strcat(g_unique_map[i], get_t_map_value(i));
        }
        else if (i % 10 == 0)
        {
            g_unique_map[i] = ft_malloc_map(get_t_map_value(i), 0, 0);
            ft_strcat(g_unique_map[i], get_t_map_value(i));
        }
        i++;
    }
    g_unique_map[1000] = 0;
    ft_fill_2num_map();
    ft_fill_3num_map();
    return (0);
}

int ft_fill_2num_map(void) // 21 ~ 99 까지 
{
    int i;
    char    *n1_str;
    char    *n2_str;

    i = 21;
    while (i < 100)
    {
        if (i % 10 != 0)  // 30 , 40 등은 이미 받아옴
        {
            n2_str = g_unique_map[i % 10];
            n1_str = g_unique_map[i - (i % 10)]; 
            g_unique_map[i] = ft_malloc_map(n1_str, n2_str, 0);
            ft_strcat(g_unique_map[i], n1_str);
            ft_strcat(g_unique_map[i], n2_str);
        }
        i++;
    }
    return (0);
}

int ft_fill_3num_map(void)
{
    int i;
    char *n1_str; // 812 에서 8
    char *n2_str; // 812 에서 100
    char *n3_str; // 812 에서 12

    i = 101;
    while (i < 1000)
    {
        n1_str = g_unique_map[i / 100];
        n2_str = g_unique_map[100];
        n3_str = g_unique_map[i % 100];
        if (i % 100 == 0)
            n3_str = 0;
        g_unique_map[i] = ft_malloc_map(n1_str, n2_str, n3_str);
        ft_strcat(g_unique_map[i], n1_str);
        ft_strcat(g_unique_map[i], n2_str);
        ft_strcat(g_unique_map[i], n3_str);
        i++;
    }
    return (0);
}
