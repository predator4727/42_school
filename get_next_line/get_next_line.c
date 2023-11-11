/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:52:26 by aderugo           #+#    #+#             */
/*   Updated: 2022/04/03 20:28:09 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*not_read(char *str)
{
	int		i;
	int		j;
	char	*part_line;

	if (!str)
		return (NULL);
	j = 0;
	while (str[j] != '\n' && str[j])
		j++;
	if (str[j] == '\0')
	{
		free(str);
		return (NULL);
	}
	i = ft_strlen(str);
	part_line = malloc((i - j) * sizeof(char));
	if (!part_line)
		return (NULL);
	i = 0;
	j++;
	while (str[j])
		part_line[i++] = str[j++];
	part_line[i] = '\0';
	free(str);
	return (part_line);
}

char	*read_line(char *str)
{
	int		i;
	char	*line;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[0] == '\0')
		return (NULL);
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*read_fd(int fd, char *str, char *temp, char *buf)
{
	int		n;

	n = 1;
	while (n)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == -1)
		{
			free (buf);
			return (NULL);
		}
		buf[n] = '\0';
		temp = str;
		if (!temp)
		{
			temp = malloc(sizeof(char));
			temp[0] = '\0';
		}
		str = ft_strjoin(temp, buf);
		free(temp);
		if (is_newline(str) == 1)
			break ;
	}
	free(buf);
	return (str);
}

int	is_newline(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	char		*temp;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = NULL;
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	str = read_fd(fd, str, temp, buf);
	if (!str)
		return (NULL);
	line = read_line(str);
	str = not_read(str);
	return (line);
}
