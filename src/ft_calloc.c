/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:56:10 by wismith           #+#    #+#             */
/*   Updated: 2022/02/20 22:32:34 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*add;
	size_t	i;

	add = malloc(nmemb * size);
	i = 0;
	if (add == NULL)
		return (add);
	add = (char *)ft_memset(add, '\0', nmemb);
	return (add);
}
