/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:52:42 by wismith           #+#    #+#             */
/*   Updated: 2023/12/03 16:45:06 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *restrict_dst, const void *restrict_src, size_t len)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*src;
	unsigned char	*temp;

	i = -1;
	dst = (unsigned char *) restrict_dst;
	src = (unsigned char *) restrict_src;
	temp = (unsigned char *) malloc(sizeof(char) * len);
	if (!temp)
		return (NULL);
	while (++i < len)
		temp[i] = src[i];
	i = -1;
	while (++i < len)
		dst[i] = temp[i];
	free (temp);
	return (dst);
}
