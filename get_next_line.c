/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrulin <hbrulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:26:33 by hbrulin           #+#    #+#             */
/*   Updated: 2019/11/21 19:36:21 by hbrulin          ###   ########.fr       */
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

int ft_fill_line(char **s, char **line)
{
    char *tmp;
    int len;

    len = 0;
    while ((*s)[len] != '\n' && (*s)[len])
        len++;
    if((*s)[len] == '\n')
    {
        *line = ft_substr(*s, 0, len);
        tmp = ft_strdup((*s) + len + 1);
        free((*s));
        (*s) = tmp;
        if ((*s)[0] == '\0')
        {
            free(*s);
            s = NULL;
        }
    }
    else if ((*s)[len] == '\0')
    {
        *line = ft_strdup(*s);
        free(*s);
        s = NULL;
        return (0);
    }
    return (1);
}

int     get_next_line(int fd, char **line)
{
    static char *s;
    char buf[BUFFER_SIZE +1];
    char *tmp;
    int ret;

    //il faut gerer le cas de l'empty line

    if (fd < 0 || line == NULL)
        return (-1);
    while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[ret] = '\0';
        if (s == NULL)
            s = ft_strnew(1);
        tmp = ft_strjoin(s, buf);
        s = tmp;
        if (ft_strchr(buf, '\n'))
            break;
    }
    if (ret < 0)
        return(-1);
    else if (ret == 0 && (s == NULL || s[0] == '\0'))
        return (0);
    return (ft_fill_line(&s, line));
}
