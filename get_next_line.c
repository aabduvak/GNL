/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42ISTANBUL.COM.TR>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 05:14:24 by aabduvak          #+#    #+#             */
/*   Updated: 2022/01/15 08:23:28 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

/**
 * @brief The function will free given string and return null
 * 
 * @param backup 
 * @return void* 
 */

static void	*ft_clear_backup(char **backup)
{
	free(*backup);
	*backup = NULL;
	return (*backup);
}

/**
 * @brief The function will create new string and return the result string
 * 
 * @param backup 
 * @return char* 
 */

static char	*ft_init_string(char **backup)
{
	char	*last_char;
	char	*result;
	size_t	backup_leng;

	if (!*backup)
		return (*backup);
	backup_leng = ft_strlen(*backup);
	if (!backup_leng)
		return (ft_clear_backup(backup));
	last_char = ft_strchr(*backup, '\n');
	if (!last_char)
	{
		result = ft_substr(*backup, 0, backup_leng);
		**backup = 0;
		return (result);
	}
	result = ft_substr(*backup, 0, last_char - *backup + 1);
	ft_strncpy(*backup, last_char + 1, backup_leng);
	return (result);
}

/**
 * @brief The function will join all slices of backup and returns it.
 * 
 * @param backup 
 * @param str 
 * @return char* 
 */

static char	*ft_update(char **backup, char *str)
{
	char	*old_slice;

	old_slice = *backup;
	*backup = ft_strjoin(*backup, str);
	if (old_slice)
		free(old_slice);
	return (*backup);
}

/**
 * @brief The function will get first line by file descriptor and returns line
 * 
 * @param fd 
 * @return char* 
 */

char	*get_next_line(int fd)
{
	char		*result;
	static char	*backup = 0;
	char		slice[BUFFER_SIZE + 1];
	int			read_bytes;

	read_bytes = 1;
	result = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (result);
	while (read_bytes && !ft_strchr(backup, '\n'))
	{
		read_bytes = read(fd, slice, BUFFER_SIZE);
		slice[read_bytes] = '\0';
		if (read_bytes < 0 || !ft_update(&backup, slice))
			return (ft_clear_backup(&backup));
	}
	result = ft_init_string(&backup);
	return (result);
}
