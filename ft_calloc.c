/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:51:51 by skayed            #+#    #+#             */
/*   Updated: 2024/12/14 15:42:05 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;

	if (count > SIZE_MAX / size)
		return (NULL);
	arr = malloc(size * count);
	if (!arr)
		return (NULL);
	ft_bzero(arr, size * count);
	return (arr);
}
