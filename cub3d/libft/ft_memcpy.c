/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyozcan <oyozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:17:13 by oyozcan           #+#    #+#             */
/*   Updated: 2024/09/27 14:48:30 by oyozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dstc;
	unsigned char	*srcc;

	i = 0;
	dstc = (unsigned char *) dst;
	srcc = (unsigned char *) src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		dstc[i] = srcc[i];
		i++;
	}
	return (dst);
}
