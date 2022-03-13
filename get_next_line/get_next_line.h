/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 18:33:43 by jiyoo             #+#    #+#             */
/*   Updated: 2021/12/02 19:27:50 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int			get_next_line(int fd, char **line);

size_t		ft_strlen(char *s);
size_t		ft_strlcpy(char *dst, char *src, size_t dstsize);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *s1);

#endif
