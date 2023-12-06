/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_mod.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:26:34 by wismith           #+#    #+#             */
/*   Updated: 2023/12/04 18:05:13 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin_mod(char *s1, char *s2, int s2size)
{
	char	*res;
	int		i;
	int		index;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	index = 0;
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + s2size + 1));
	if (!res)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2 && s2[index] != '\0')
		res[i++] = s2[index++];
	res[i] = '\0';
	if (s1)
		ft_free(s1);
	return (res);
}
