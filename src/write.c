/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:40:53 by aautin            #+#    #+#             */
/*   Updated: 2023/07/19 21:45:10 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	write_management_errors(int option, char *av)
{
	int	i;

	i = 0;
	if (option == -1)
	{
		write(1, "can't read or open the file ", 28);
		while (av[i])
		{
			write(1, &av[i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
	else if (option == 0)
	{
		write(1, "map error\n", 10);
	}
}
