/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:31:23 by wismith           #+#    #+#             */
/*   Updated: 2022/02/21 16:25:52 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}

int	ft_nlel(char *s)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2, int s2size)
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

char	*ft_rtnline(char *s)
{
	char	*res;
	int		i;

	if (!s)
		return (NULL);
	if (s[0] == '\0')
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	i++;
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	res[i] = '\0';
	i -= 1;
	while (i >= 0)
	{
		res[i] = s[i];
		i--;
	}
	return (res);
}

char	*ft_rtnsave(char *s)
{
	char	*res;
	int		i;
	int		index;

	if (!s)
		return (NULL);
	if (!ft_nlel(s))
		return (ft_free(s));
	i = 0;
	index = 0;
	while (s[i] != '\n')
		i++;
	res = (char *)malloc(sizeof(char) * (ft_strlen(s) - i + 1));
	if (!res)
		return (NULL);
	while (s[++i] != '\0')
	{
		res[index] = s[i];
		index++;
	}
	res[index] = '\0';
	ft_free(s);
	return (res);
}
