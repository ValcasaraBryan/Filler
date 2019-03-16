/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:53:38 by roliveir          #+#    #+#             */
/*   Updated: 2018/12/12 15:46:21 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int		get_newline(char **isread, char **line, int fd)
{
	int		i;
	char	*temp;

	i = 0;
	while (isread[fd][i] != '\n' && isread[fd][i])
		i++;
	if (isread[fd][i] == '\n')
	{
		if ((*line = ft_strsub(isread[fd], 0, i)) == NULL)
			return (-1);
		if ((temp = ft_strdup(isread[fd] + i + 1)) == NULL)
			return (-1);
		free(isread[fd]);
		isread[fd] = temp;
		if (isread[fd][0] == '\0')
			ft_strdel(&isread[fd]);
	}
	else if (isread[fd][i] == '\0')
	{
		if ((*line = ft_strdup(isread[fd])) == NULL)
			return (-1);
		ft_strdel(&isread[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*isread[511];
	char		buf[BUFF_SIZE + 1];
	int			ret;
	char		*tmp;

	ret = 1;
	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (!isread[fd])
			isread[fd] = ft_strnew(1);
		buf[ret] = '\0';
		if ((tmp = ft_strjoin(isread[fd], buf)) == NULL)
			return (-1);
		free(isread[fd]);
		isread[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			return (get_newline(isread, line, fd));
	}
	if (ret == -1)
		return (-1);
	else if (ret == 0 && isread[fd] == NULL)
		return (0);
	return (get_newline(isread, line, fd));
}
