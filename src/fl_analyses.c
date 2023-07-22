/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_analyses.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:40:53 by aautin            #+#    #+#             */
/*   Updated: 2023/07/19 16:27:08 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	fl_size(char *fl_name)
{
	t_file	file;

	file.descriptor = open(fl_name, O_RDONLY);
	if (file.descriptor == -1)
		return (file.descriptor);
	file.size = 1;
	file.content = (char *)malloc(file.size * sizeof(char));
	while (read(file.descriptor, file.content, 1) > 0)
	{
		free(file.content);
		file.size ++;
		file.content = (char *)malloc(file.size * sizeof(char));
	}
	free(file.content);
	close(file.descriptor);
	return (file.size);
}

int	fl_to_str(t_file *file, char *fl_name)
{
	file->descriptor = open(fl_name, O_RDONLY);
	if (file->descriptor == -1)
		return (0);
	file->content = (char *)malloc(file->size * sizeof(char));
	read(file->descriptor, file->content, file->size);
	file->content[file->size - 1] = '\0';
	close(file->descriptor);
	return (1);
}
