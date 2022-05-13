/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:45:10 by mvavasso          #+#    #+#             */
/*   Updated: 2022/05/13 03:54:01 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	temp = ft_substr(str[0], i + 2, ft_strlen(str[0]));
	free(str[0]);
	str[0] = ft_strdup(temp);
	if (str[0][i + 1] != '\n')
	{
		free(str[0]);
		str[0] = NULL;
		if (!ft_strlen(line))
			free(line);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*str;
	int			fread;
	static char	*s_line;
	char		*temp;

	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	fread = read(fd, str, BUFFER_SIZE);
	while (fread > 0)
	{
		str[fread] = '\0';
		if (s_line == NULL)
			s_line = ft_strdup(str);
		else
		{
			temp = ft_strjoin(s_line, str);
			free(s_line);
			s_line = temp;
		}
		if (ft_strchr(s_line, '\n'))
			break ;
		fread = read(fd, str, BUFFER_SIZE);
	}
	return (free(str), another_split(&s_line));
}

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*result = "oi";
	int		fd;
	
	fd = open("file", O_RDONLY);
	while (result)
	{
		result = get_next_line(fd);
		printf("%s", result);
	}
	return (0);
}