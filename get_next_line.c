/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrulin <hbrulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:26:33 by hbrulin           #+#    #+#             */
/*   Updated: 2019/11/25 12:55:45 by hbrulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*s2;

	if (!s)
		return (NULL);
	i = 0;
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	s2 = (char *)malloc(sizeof(*s2) * len + 1);
	if (s2 == NULL)
		return (NULL);
	while (len)
	{
		s2[i] = s[start];
		start++;
		i++;
		len--;
	}
	s2[i] = '\0';
	return (s2);
}

int		ft_fill_line(char **s, char **line, int len)
{
	char	*tmp;

	if ((*s)[len] == '\n')
	{
		*line = ft_substr(*s, 0, len);
		tmp = ft_strdup((*s) + len + 1);
		free((*s));
		(*s) = tmp;
		if ((*s)[0] == '\0')
		{
			free(*s);
			*s = NULL;
		}
	}
	else if ((*s)[len] == '\0')
	{
		*line = ft_strdup(*s);
		free(*s);
		*s = NULL;
		return (0);
	}
	return (1);
}

int		ft_return(char **line, char **s, int ret)
{
	int len;

	len = 0;
	if (ret < 0)
	{
		*line = ft_strdup("");
		return (-1);
	}
	else if (ret == 0 && (*s == NULL))
	{
		*line = ft_strdup("");
		return (0);
	}
	while ((*s)[len] != '\n' && (*s)[len])
		len++;
	return (ft_fill_line(s, line, len));
}

int		get_next_line(int fd, char **line)
{
	static char		*s;
	char			buf[BUFFER_SIZE + 1];
	char			*tmp;
	int				ret;

	if (line == NULL)
		return (-1);
	if (fd < 0 || BUFFER_SIZE == 0)
	{
		*line = ft_strdup("");
		return (-1);
	}
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (s == NULL)
			s = ft_strnew(1);
		tmp = ft_strjoin(s, buf);
		free(s);
		s = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (ft_return(line, &s, ret));
}
