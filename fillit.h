/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 12:30:12 by jraty             #+#    #+#             */
/*   Updated: 2020/08/25 12:34:47 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "libft/libft.h"
#include <fcntl.h>

//
#include <stdio.h>
//

# define BUF_SIZE 21

//decided to scrap grid struct for global grid size
int	GRID_SIZE;

typedef	struct		s_tetro
{
	char			*raw;
	int				letter;
	int				x[4];
	int				y[4];
	struct s_tetro	*next;
	struct s_tetro	*prev;
}					t_tetro;

//int		ft_safe_move(t_tetro **tetro, int x_max, int y_max, int x, int y);

int		ft_recursive(t_tetro **s_tetro, int **grid);

t_tetro	*ft_reset_coordinates(t_tetro **tetro, int **grid);

int		ft_move_1(t_tetro **tetro, int **grid);

int		ft_judge_grid(int **grid);

char	**ft_abc_grid(t_tetro *list);

int		**ft_reset_grid(int **grid);

int		**ft_generate_answer(t_tetro *s_tetro, int **grid);

int		**ft_flip_grid(t_tetro *tetro, int **grid);

int		**ft_make_grid(int **grid);

int		ft_board_size(int nb);

int		ft_move_coordinate(t_tetro **tetro, int x, int y, int **grid);

int		ft_error(int n);

int		ft_checker1(int fd);

int		ft_checker2(int fd);

char	**ft_file_save(int fd, char **argv);

char	**ft_single_shapes(char *f_content);

size_t	ft_file_size(int fd);

t_tetro	*ft_process_raw(char **raw);

t_tetro	*new_tetro(char *tetro_string, t_tetro *previous, int i);

void	ft_set_coordinates(t_tetro **element);




#endif
