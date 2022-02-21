/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:29:45 by wismith           #+#    #+#             */
/*   Updated: 2022/02/17 22:11:39 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# define BUFFER_SIZE 8
# include <unistd.h>
# include <stdlib.h>

int		ft_strlen(char *s);
int		ft_nlel(char *s);
char	*ft_strjoin(char *s1, char *s2, int s2size);
char	*ft_rtnline(char *s);
char	*ft_rtnsave(char *s);
char	*get_next_line(int fd);
char	*ft_free(char *s);
#endif