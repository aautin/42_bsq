/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bsq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:41:57 by yhsiao            #+#    #+#             */
/*   Updated: 2023/07/19 15:32:34 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	sq_calc(int **area, int **sol_area, int i, int j)
{
	int	nb;
	int	up;
	int	left;
	int	left_up;

	nb = area[i][j];
	if (i == 0 || j == 0 || nb == 0)
		return (nb);
	left = sol_area[i][j - 1];
	up = sol_area[i - 1][j];
	left_up = sol_area[i - 1][j - 1];
	if (up <= left && up <= left_up)
		return (up + nb);
	else if (left <= up && left <= left_up)
		return (left + nb);
	else
		return (left_up + nb);
}

int	**find_bsq(int **area, t_map *map)
{
	int	i;
	int	j;
	int	**sol_area;

	sol_area = create_empty_array(*map);
	map->bsq_row = 0;
	map->bsq_col = 0;
	map->bsq_size = sol_area[map->bsq_row][map->bsq_col];
	i = -1;
	while (++i < map->row_nb)
	{
		j = -1;
		while (++j < map->col_nb)
		{
			sol_area[i][j] = sq_calc(area, sol_area, i, j);
			if (sol_area[i][j] > sol_area[map->bsq_row][map->bsq_col])
			{
				map->bsq_row = i;
				map->bsq_col = j;
				map->bsq_size = sol_area[map->bsq_row][map->bsq_col];
			}
		}
	}
	return (sol_area);
}
