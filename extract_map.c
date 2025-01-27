/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarzila <abarzila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:36:54 by abarzila          #+#    #+#             */
/*   Updated: 2025/01/21 08:12:26 by abarzila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*update_str(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free(s1);
	free(s2);
	return (str);
}

/*convert the .ber file into a character string*/
char	*set_up_map(char *str)
{
	int		fd;
	char	*map;
	char	*tmp;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error\nCheck file input\n", ERROR), NULL);
	map = malloc(sizeof(char) * 1);
	if (!map)
		return (ft_putstr_fd("Error\nMalloc failed\n", ERROR), NULL);
	map[0] = '\0';
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		map = update_str(map, tmp);
		if (!map)
		{
			free(tmp);
			return (ft_putstr_fd("Error\nMalloc failed\n", ERROR), NULL);
		}
	}
	close(fd);
	return (map);
}
