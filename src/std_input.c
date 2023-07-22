/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:40:53 by aautin            #+#    #+#             */
/*   Updated: 2023/07/19 22:13:08 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	dest_len;
	int	i;

	dest_len = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

void	read_std_input(t_file *std)
{
	char	*tp_str;

	std->content = (char *)malloc((10001 * 10001) * sizeof(char));
	std->content[0] = '\0';
	tp_str = (char *)malloc(10001 * sizeof(char));
	read(1, tp_str, 10001);
	while (tp_str[0] != '\n' && tp_str[0])
	{
		ft_strcat(std->content, tp_str);
		free(tp_str);
		tp_str = (char *)malloc(10001 * sizeof(char));
		read(1, tp_str, 10001);
	}
	free(tp_str);
}
