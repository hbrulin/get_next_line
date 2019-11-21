#include "get_next_line.h"

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

int		checkerror(int fd, char **str, char **line)
{
	if (fd < 0 || line == NULL)
		return (-1);
	if (!*str)
	{
		if (!(*str = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
	}
	return (0);
}

char	*readline(char *str, int fd)
{
	char		buff[BUFFER_SIZE + 1];
	int			ret;

	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		str = ft_strjoin(str, buff);
	}
	return (str);
}

int		get_next_line(int const fd, char **line)
{
	static char	*str;
	int			i;

	if (checkerror(fd, &str, line) == -1)
		return (-1);
	if (*str)
		ft_strcpy(*line, str);
	str = readline(str, fd);
	i = 0;
	if (str[i])
	{
		while (str[i] != '\n' && str[i])
			i++;
		if (i == 0)
        {
			(*line) = ft_strdup(str);
			free(str);
            return(0);
        }
		else
		{
			(*line) = ft_substr(str, 0, i);
			str = &str[i + 1];
            return (1);
		}
	}
	else
	{
		(*line) = ft_strdup(str);
	}
	
	return (0);
}
