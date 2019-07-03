/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 13:35:57 by pacovali      #+#    #+#                 */
/*   Updated: 2019/02/04 11:44:55 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_gnl_list	*get_fd_list(ssize_t fd, t_gnl_list **firstlist)
{
	t_gnl_list *list;
	t_gnl_list *new;

	list = *firstlist;
	if (list != NULL && list->fd == fd)
		return (*firstlist);
	while (list != NULL && list->next != NULL)
	{
		if (list->next->fd == fd)
			return (list->next);
		list = list->next;
	}
	if (
		(new = (t_gnl_list*)ft_memalloc(sizeof(t_gnl_list))) == NULL ||
		(new->str = (char*)ft_memalloc(BUFF_SIZE)) == NULL)
		return (NULL);
	new->fd = fd;
	return (list == NULL
	?
	(*firstlist = new)
	:
	(list->next = new));
}

static void			free_fd_item(t_gnl_list **firstlist, t_gnl_list *item)
{
	t_gnl_list			*to_free;

	to_free = *firstlist;
	while (to_free->next != NULL && to_free->next->fd != item->fd)
		to_free = to_free->next;
	if (to_free->next == item)
		to_free->next = to_free->next->next;
	else
		*firstlist = item->next;
	ft_memdel((void **)&(item->str));
	ft_memdel((void **)&item);
}

static char			*cpy_to_line(char **line, ssize_t *len, char *add,
							ssize_t add_len)
{
	char *new_line;

	new_line = ft_strnew(*len + add_len);
	if (new_line == NULL)
		return (NULL);
	ft_memcpy(new_line, *line, *len);
	ft_memcpy(new_line + *len, add, add_len);
	*len += add_len;
	if (line != NULL && *line != NULL)
		ft_memdel((void**)line);
	*line = new_line;
	return (new_line);
}

static int			get_from_item(char **line, t_gnl_list *item, ssize_t *len)
{
	ssize_t lbc;

	lbc = 0;
	if (item->str_len == -1)
		return (-1);
	while (lbc < item->str_len && item->str[lbc] != '\n')
		lbc++;
	if (lbc == item->str_len)
	{
		if (cpy_to_line(line, len, item->str, item->str_len) == NULL)
			return (-1);
		len += item->str_len;
		return (0);
	}
	else
	{
		if (cpy_to_line(line, len, item->str, lbc) == NULL)
			return (-1);
		ft_memmove(item->str, item->str + lbc + 1,
				item->str_len - (lbc + (ssize_t)1));
		item->str_len -= lbc + (ssize_t)1;
		return (1);
	}
}

int					get_next_line(const int fd, char **line)
{
	static t_gnl_list	*firstlist;
	t_gnl_list			*item;
	ssize_t				len;
	int					ret;

	len = 0;
	if (fd < 0 || line == NULL || BUFF_SIZE < 1 ||
		((*line = ft_strnew(0)) == NULL) ||
		((item = get_fd_list(fd, &firstlist)) == NULL))
		return (-1);
	ret = get_from_item(line, item, &len);
	if (ret != 0)
		return (ret);
	while (
		(item->str_len = read(fd, item->str, BUFF_SIZE)) != 0)
	{
		ret = get_from_item(line, item, &len);
		if (ret == -1)
			free_fd_item(&firstlist, item);
		if (ret != 0)
			return (ret);
	}
	free_fd_item(&firstlist, item);
	return (len != 0);
}
