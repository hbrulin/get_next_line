/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrulin <hbrulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:26:42 by hbrulin           #+#    #+#             */
/*   Updated: 2019/11/22 14:02:47 by hbrulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int i;
	int len;

	len = ft_strlen(src);
	i = 0;
	while (i <= len)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	int		s_len;
	char	*dst;

	s_len = ft_strlen(s1);
	dst = (char *)malloc(sizeof(char) * s_len + 1);
	if (dst == NULL)
		return (NULL);
	ft_strcpy(dst, s1);
	dst[s_len] = '\0';
	return (dst);
}

char	*ft_boucle(char const *s1, char const *s2, char *s3)
{
	int		i;
	int		j;
	size_t	s1len;
	size_t	s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	i = 0;
	j = 0;
	while (s1len--)
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2len--)
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	return (s3);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	s1len;
	size_t	s2len;

	if (!(s1 && s2))
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (!(s3 = (char *)malloc(sizeof(*s3) * (s1len + s2len + 1))))
		return (NULL);
	return (ft_boucle(s1, s2, s3));
}
