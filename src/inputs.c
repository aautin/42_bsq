/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:40:53 by aautin            #+#    #+#             */
/*   Updated: 2023/07/19 21:06:20 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	fl_input(char *av[], int ac)
{
	int		i;
	t_file	file;
	t_map	map;

	i = 0;
	while (++i < ac)
	{
		if (i > 1 && i < ac)
			write(1, "\n", 1);
		file.size = fl_size(av[i]);
		if (file.size == -1 || !fl_to_str(&file, av[i]))
		{
			write_management_errors(-1, av[i]);
			continue ;
		}
		else if (!is_str_formated(file, &map))
		{
			write_management_errors(0, av[i]);
			free(file.content);
			continue ;
		}
		bsq_solver(file.content, map);
		free(file.content);
	}
}

void	std_input(void)
{
	t_file	std;
	t_map	map;

	read_std_input(&std);
	if (!is_str_formated(std, &map))
	{
		write_management_errors(0, "your std input");
		free(std.content);
		return ;
	}
	bsq_solver(std.content, map);
	free(std.content);
}
