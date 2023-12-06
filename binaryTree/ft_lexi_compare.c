/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexi_compare.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 00:04:30 by wismith           #+#    #+#             */
/*   Updated: 2023/12/03 16:32:32 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binaryTree.h"

/*
*	if first is greater than / or equal to second the return will be 0
*		else the return will be 1
*/
int	ft_lexi_compare(const void *first, const void *second)
{
	size_t			i;
	size_t			j;
	unsigned char	*fkey;
	unsigned char	*skey;

	i = ft_strlen(first);
	j = ft_strlen(second);
	fkey = (unsigned char *) first;
	skey = (unsigned char *) second;
	while ((fkey != (first + i)) && (skey != (second + j)))
	{
		if (*fkey < *skey)
			return (1);
		if (*(fkey++) > *(skey++))
			return (0);
	}
	return ((fkey == (first + i)) && (skey != (second + j)));
}
