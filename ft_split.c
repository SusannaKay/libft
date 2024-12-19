/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@>                           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:31:25 by skayed            #+#    #+#             */
/*   Updated: 2024/12/19 22:07:40 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
static int ft_count(const char *s, char c)
{
    int count;
    int dim;
    int i;

    count = 0;
    dim = 0;
    i = 0;
    while (s[i] != '\0')
    {
        while (s[i] == c)
            i++;
        while (s[i] != c && s[i] != '\0')
        {
            dim++;
            i++;
        }
        if (dim > 0)
        {
            count++;
            dim = 0;
        }
    }
    if (count == 0)
        count = 1;
    return (count);
}
static char *ft_copy(int start, int end, const char *src, char *dest)
{
    int i;
    i = 0;
    while (start < end)
    {
        dest[i] = src[start];
        i++;
        start++;
    }
    dest[i] = '\0';
    return (dest);
}
int ft_countstart(char const *s, char c, int i)
{
    while (s[i] && s[i] == c)
        i++;
    return (i);
}
int ft_countend(char const *s, char c, int i)
{
    while (s[i] && s[i] != c)
        i++;
    return (i);
}
char **ft_split(char const *s, char c)
{
    int start;
    int end;
    int i;
    int j;
    int row;
    char **spd;

    start = 0;
    row = ft_count(s, c);
    j = 0;
    i = 0;
    if (!s)
        return (NULL);
    spd = (char **)malloc((row + 1) * sizeof(char *));
    if (!spd)
        return (NULL);
    while (s[i] != '\0' && j < row)
    {
        start = ft_countstart(s, c, i);
        end = ft_countend(s, c, start);
        if (end > start)
        {
            spd[j] = (char *)malloc((end - start + 2) * sizeof(char));
            if (!spd[j])
            {
                while (j > 0)
                {
                    free(spd[j - 1]);
                    j--;
                }
                free(spd);
                return (NULL);
            }
            ft_copy(start, end, s, spd[j]);
            j++;
        }
        i = end;
    }
    spd[j] = NULL;
    return (spd);
}
