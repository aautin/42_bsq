/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:40:53 by aautin            #+#    #+#             */
/*   Updated: 2023/07/19 16:27:10 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_atoi(char *str, int max)
{
	int	i;
	int	dash_nb;
	int	nb;

	i = 0;
	dash_nb = 1;
	nb = 0;
	if (str[i] == '-' && i < max)
	{
		dash_nb = dash_nb * -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9' && i < max)
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb * dash_nb);
}
