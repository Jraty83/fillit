/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 12:30:12 by jraty             #+#    #+#             */
/*   Updated: 2020/09/03 09:57:54 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

# include <fcntl.h>

typedef	struct		s_tetro
{
	char			*raw;
	int				letter;
	int				x[4];
	int				y[4];
	struct s_tetro	*next;
	struct s_tetro	*prev;
}					t_tetro;

char				**ft_fill_abc(t_tetro *tetro, char **grid, int sz, int gs);

char				**ft_abc_grid(t_tetro *list, int grid_size);

void				ft_print_grid_abc(t_tetro *tetro, int grid_size);

int					**ft_flip_grid(t_tetro *tetro, int **grid);

int					**ft_bool_2d(int **grid, int size);

int					ft_board_size(int nb);

int					ft_validate_coordinate(t_tetro *tetro, int **grid, int gs);

void				ft_move_coordinate(t_tetro **tetro, int x, int y);

char				**ft_file_save(int fd, char **argv);

char				**ft_single_shapes(char *f_content);

int					ft_solver(t_tetro **s_tetro, int **grid, int grid_size);

void				ft_tetro_next(t_tetro **tetro, int *x, int *y);

void				ft_grid_bigger(int *grid_size, int *x, int *y);

void				ft_tetro_prev(t_tetro **tetro, int *x, int *y);

void				ft_start_new_line(int *x, int *y);

size_t				ft_tetro_count(t_tetro *struct_tetro);

void				ft_set_coordinates(t_tetro **element);

t_tetro				*ft_process_raw(char **raw);

t_tetro				*ft_new_tetro(char *tetro_string, t_tetro *previous, int i);

int					ft_usage(void);

int					ft_error(void);

int					ft_reading(int fd, int *i, int *l, char *line);

int					ft_check_connect(int i, char *buf, int *hash, int *conn);

int					ft_checker1(int fd);

int					ft_checker2(int fd);

#endif
