/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:14:58 by mvavasso          #+#    #+#             */
/*   Updated: 2022/05/12 16:43:29 by mvavasso         ###   ########.fr       */
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
