/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_analyses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:40:53 by aautin            #+#    #+#             */
/*   Updated: 2023/07/19 22:31:39 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	is_str_formated(t_file file, t_map *str)
{
	int	i;
	int	j;
	int	row_nb;

	i = 0;
	while (file.content[i] && file.content[i] != '\n')
		i++;
	str->row_nb = ft_atoi(file.content, i - 2);
	j = i;
	while (file.content[i + 1] && file.content[i + 1] != '\n')
		i++;
	str->col_nb = i - j;
	row_nb = 0;
	while (file.content[++i])
	{
		if (file.content[i] == '\n')
			row_nb++;
		if (file.content[i] == '\n' && ((i - j) % (str->col_nb + 1) != 0
				|| !is_empty_or_obs(file, str, j + 1)))
			return (0);
	}
	if (row_nb != str->row_nb)
		return (0);
	return (1);
}

int	is_empty_or_obs(t_file file, t_map *str, int i)
{
	str->full_c = file.content[i - 2];
	str->empty_c = file.content[i - 4];
	str->obstacle_c = file.content[i - 3];
	while (file.content[i])
	{
		if (file.content[i] != str->empty_c
			&& file.content[i] != str->obstacle_c && file.content[i] != '\n')
			return (0);
		i++;
	}
	if (str->full_c < 32 || str->full_c > 126)
		return (0);
	if (str->empty_c < 32 || str->empty_c > 126)
		return (0);
	if (str->obstacle_c < 32 || str->obstacle_c > 126)
		return (0);
	return (1);
}
