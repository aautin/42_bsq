/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_solver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsiao <yhsiao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:33:22 by yhsiao            #+#    #+#             */
/*   Updated: 2023/07/19 21:50:24 by yhsiao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	**str_to_map(char *str, t_map map)
{
	char	**strs;
	int		**area;
	int		i;
	int		j;

	strs = ft_split(str, "\n");
	area = create_empty_array(map);
	i = -1;
	while (++i < map.row_nb)
	{
		j = -1;
		while (++j < map.col_nb)
		{
			if (strs[i + 1][j] == map.empty_c)
				area[i][j] = 1;
			else
				area[i][j] = 0;
		}
	}
	i = -1;
	while (++i < map.row_nb + 1)
		free(strs[i]);
	free(strs);
	return (area);
}

void	print_bsq_map(int **area, t_map map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map.row_nb)
	{
		j = -1;
		while (++j < map.col_nb)
		{
			if ((i >= map.bsq_row - map.bsq_size + 1 && i <= map.bsq_row) \
			&& (j >= map.bsq_col - map.bsq_size + 1 && j <= map.bsq_col))
				write(1, &map.full_c, 1);
			else if (area[i][j] == 1)
				write(1, &map.empty_c, 1);
			else
				write(1, &map.obstacle_c, 1);
		}
		write(1, "\n", 1);
	}
}

void	print_obstacle_map(t_map map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map.row_nb)
	{
		j = -1;
		while (++j < map.col_nb)
			write(1, &map.obstacle_c, 1);
		write(1, "\n", 1);
	}
}

void	bsq_solver(char *str, t_map map)
{
	int		**area;
	int		**sol_area;

	area = str_to_map(str, map);
	sol_area = find_bsq(area, &map);
	if (map.bsq_size == 0)
		print_obstacle_map(map);
	else
		print_bsq_map(area, map);
	free_area(area, map);
	free_area(sol_area, map);
}
