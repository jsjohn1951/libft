/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:29:26 by wismith           #+#    #+#             */
/*   Updated: 2023/12/04 15:38:36 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	char	*s;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	s = (char *) src;
	if (dstlen >= dstsize)
		return (ft_strlen(s) + dstsize);
	if (srclen < dstsize - dstlen)
	{
		ft_memcpy(dst + dstlen, src, srclen);
		dst[dstlen + srclen] = '\0';
		return (dstlen + srclen);
	}
	ft_memcpy(dst + dstlen, src, dstsize - dstlen - 1);
	dst[dstsize - 1] = '\0';
	return (dstlen + srclen);
}
