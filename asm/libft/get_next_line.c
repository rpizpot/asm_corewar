/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <rpizpot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 00:11:24 by rpizpot           #+#    #+#             */
/*   Updated: 2019/05/13 21:07:51 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	i;

	if (s1 && s2)
	{
		i = 0;
		new_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (!new_str)
			return (NULL);
		new_str = ft_strcpy(new_str, s1);
		while (i < ft_strlen(s2))
		{
			new_str[ft_strlen(s1) + i] = s2[i];
			i++;
		}
		new_str[ft_strlen(s1) + i] = '\0';
		return (new_str);
	}
	return (NULL);
}

void	ft_read_data(int file_desc, char *read_data, char **storage)
{
	char		*str_tmp;
	int			ret;

	while ((ret = read(file_desc, read_data, BUFF_SIZE)) > 0)
	{
		read_data[ret] = '\0';
		if (*storage)
		{
			str_tmp = *storage;
			*storage = ft_strjoin_gnl(str_tmp, read_data);
			ft_strdel(&str_tmp);
		}
		else
			*storage = ft_strdup(read_data);
		if (ft_strchr(read_data, '\n'))
			break ;
	}
	ft_strdel(&read_data);
}

int		ft_get_line(char **storage, char **line)
{
	char		*str_tmp;
	char		*str_tmp2;

	if (!*storage)
		return (0);
	if ((str_tmp = ft_strchr(*storage, '\n')) == NULL)
		return (0);
	*str_tmp = '\0';
	*line = ft_strdup(*storage);
	str_tmp2 = *storage;
	*storage = ft_strdup(str_tmp + 1);
	ft_strdel(&str_tmp2);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char *storage[MAX_FILE_DESC + 1];
	char		*read_data;
	int			ret;

	ret = 0;
	if (fd < 0 || fd > MAX_FILE_DESC || !line || BUFF_SIZE < 1 ||
	read(fd, storage[fd], 0) < 0 || !(read_data = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (!ft_strchr(storage[fd], '\n'))
		ft_read_data(fd, read_data, &storage[fd]);
	if (ft_get_line(&storage[fd], line))
		return (1);
	else
	{
		if (!storage[fd] || storage[fd][0] == '\0')
			return (0);
	}
	*line = storage[fd];
	storage[fd] = NULL;
	return (1);
}
