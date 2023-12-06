/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:55:30 by wismith           #+#    #+#             */
/*   Updated: 2023/12/06 19:43:57 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi(const char *nptr)
{
	size_t	res;
	int		i;
	int		negative;

	res = 0;
	i = 0;
	negative = 1;
	while ((nptr[i] >= 7 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if ((nptr[i] == '-' || nptr[i] == '+') && nptr[i++] == '-')
		negative = -1;
	while (nptr[i] && (nptr[i] >= 48 && nptr[i] <= 57))
		res = (res * 10) + nptr[i++] - '0';
	if (res >= 9223372036854775807 && negative == 1)
		return (-1);
	if (res >= 9223372036854775807 && negative == -1)
		return (0);
	return ((res * negative));
}
