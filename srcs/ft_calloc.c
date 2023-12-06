/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:56:10 by wismith           #+#    #+#             */
/*   Updated: 2023/12/04 17:51:16 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*add;

	add = malloc(nmemb * size);
	if (add == NULL)
		return (add);
	add = (char *)ft_memset(add, '\0', nmemb);
	return (add);
}
