/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:14:58 by mvavasso          #+#    #+#             */
/*   Updated: 2022/06/01 23:32:31 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int find)
{
	int	i;

	i = 0;
	if (find > 255)
		return ((void *)str);
	while (str[i])
	{
		if (str[i] == find)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == find)
		return ((char *)&str[i]);
	return (NULL);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		i;

	i = ft_strlen(src);
	dup = (char *) malloc((i + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	i;
	int		size;
	int		aux;

	i = 0;
	aux = 0;
	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[aux])
	{
		str[i] = s2[aux++];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	tsize;
	size_t	ssize;

	i = 0;
	ssize = ft_strlen(s);
	if (start >= ssize)
		tsize = 1;
	else if (len >= ssize)
		tsize = ssize - start + 1;
	else
		tsize = len + 1;
	substr = malloc(tsize);
	if (!substr)
		return (NULL);
	while ((start < ssize) && (i < len))
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = 0;
	return (substr);
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}
