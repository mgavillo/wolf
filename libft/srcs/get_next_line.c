/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgavillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:30:43 by mgavillo          #+#    #+#             */
/*   Updated: 2019/01/05 17:52:49 by mgavillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

static int		ft_supelement(t_list *list)
{
	t_list	*before;
	t_list	*first;

	first = list;
	before = list;
	while (list->next && list->content != '\0')
	{
		before = list;
		list = list->next;
	}
	before->next = list->next;
	free(list->content);
	return (0);
}

static int		ft_assign(int fd, t_list *list, char **line)
{
	t_list			*first;
	char			*tmp;
	unsigned long	i;
	char			*s;

	first = list;
	i = 0;
	while (list->content_size != (size_t)fd && list->next)
		list = list->next;
	s = list->content;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (i == 0 && s[i] == '\0')
		return (ft_supelement(first));
	*line = ft_strnew(i + 1);
	line[0][i] = '\0';
	ft_strncpy(*line, s, i);
	if (s[i] == '\n')
		i++;
	tmp = ft_strnew(1);
	tmp = ft_strjoinfree(tmp, (char *)&s[i]);
	ft_strdel(&s);
	list->content = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (1);
}

static int		ft_fd(t_list *list, const int fd)
{
	while (list)
	{
		if (list->content_size == (size_t)fd)
			return (1);
		list = list->next;
	}
	return (0);
}

static t_list	*newelement(t_list *list, const int fd, char *str)
{
	t_list	*first;
	t_list	*element;

	first = list;
	if (!(element = malloc(sizeof(*element))))
		return (NULL);
	element->content = str;
	element->content_size = (size_t)fd;
	element->next = NULL;
	if (list == NULL)
		return (element);
	while (list->next)
		list = list->next;
	list->next = element;
	return (first);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*list;
	char			*str;
	unsigned long	res;
	char			*buf;

	buf = ft_strnew(BUFF_SIZE + 1);
	if (fd < 0 || !line || BUFF_SIZE < 1 || read(fd, buf, 0) != 0)
		return (-1);
	if (!(ft_fd(list, fd)))
		str = ft_strnew(1);
	while ((res = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[res] = '\0';
		str = ft_strjoinfree(str, buf);
	}
	ft_strdel(&buf);
	if (!(ft_fd(list, fd)))
		list = newelement(list, fd, str);
	return (ft_assign(fd, list, line));
}
