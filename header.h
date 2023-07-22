/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:40:53 by aautin            #+#    #+#             */
/*   Updated: 2023/07/19 22:34:56 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_file
{
	int		size;
	int		descriptor;
	char	*content;
}			t_file;

typedef struct s_map
{
	int		size;
	int		row_nb;
	int		col_nb;
	char	empty_c;
	char	obstacle_c;
	char	full_c;
	int		bsq_row;
	int		bsq_col;
	int		bsq_size;
}			t_map;

// fl_analyses
int			fl_size(char *fl_name);
int			fl_to_str(t_file *file, char *fl_name);

// main
int			main(int ac, char *av[]);

// write
void		write_management_errors(int option, char *av);

// str_analyses
int			is_str_formated(t_file file, t_map *str);
int			is_empty_or_obs(t_file file, t_map *str, int i);

// atoi
int			ft_atoi(char *str, int max);

char		**ft_split(char *str, char *charset);

// utilities
int			**create_empty_array(t_map map);
void		free_area(int **area, t_map map);

// find_bsq
int			sq_calc(int **area, int **sol_area, int i, int j);
int			**find_bsq(int **area, t_map *map);

// bsq_solver
int			**str_to_map(char *str, t_map map);
void		print_bsq_map(int **area, t_map map);
void		print_obstacle_map(t_map map);
void		bsq_solver(char *str, t_map map);

// inputs
void		std_input(void);
void		fl_input(char *av[], int ac);

// std_inputs
void		read_std_input(t_file *std);
int			ft_strlen(char *str);
char		*ft_strcat(char *dest, char *src);

#endif