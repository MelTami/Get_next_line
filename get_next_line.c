/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:45:10 by mvavasso          #+#    #+#             */
/*   Updated: 2022/05/12 16:43:46 by mvavasso         ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	char	*str;
	int		fread;
	
	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	fread = read(fd, str, BUFFER_SIZE);
	while (fread)
	{
		str[fread] = '\0';
		
		fread = read(fd, str, BUFFER_SIZE);
	}
}

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*result;
	int		fd;
	
	fd = open("file", O_RDONLY);
	result = get_next_line(fd);
	printf("%s\n", result);
	return (0);
}