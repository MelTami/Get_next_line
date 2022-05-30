/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:09:21 by mvavasso          #+#    #+#             */
/*   Updated: 2022/05/30 21:22:12 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_free(char **str)
{
	if (str[0])
	{
		free(str[0]);
		str[0] = NULL;
	}
}

char	*another_split(char **str)
{
	char	*line;
	int		i;
	char	*temp;

	if (str[0] == NULL)
		return (NULL);
	i = 0;
	while (str[0][i] != '\0' && str[0][i] != '\n')
		i++;
	line = ft_substr(str[0], 0, i + 1);
	temp = ft_strdup(str[0]);
	ft_free(str);
	str[0] = ft_substr(temp, i + 1, ft_strlen(temp));
	ft_free(&temp);
	if (!(ft_strchr(line, '\n')))
	{
		ft_free(str);
		if (!ft_strlen(line))
			ft_free(&line);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*str;
	int			fread;
	static char	*s_line[OPEN_MAX];
	char		*temp;

	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	fread = read(fd, str, BUFFER_SIZE);
	while (fread > 0)
	{
		str[fread] = '\0';
		if (s_line[fd] == NULL)
			s_line[fd] = ft_strdup(str);
		else
		{
			temp = ft_strjoin(s_line[fd], str);
			ft_free(&s_line[fd]);
			s_line[fd] = temp;
		}
		if (ft_strchr(s_line[fd], '\n'))
			break ;
		fread = read(fd, str, BUFFER_SIZE);
	}
	return (ft_free(&str), another_split(&s_line[fd]));
}
