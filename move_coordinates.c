/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_coordinates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 14:46:37 by ekinnune          #+#    #+#             */
/*   Updated: 2020/08/28 00:35:51 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
t_tetro	*ft_change_coordinates(t_tetro **tetro, char **board, int x_max,int y_max)
{
	int i;
	int j;

	i = 0;
	j = 0;
//	im moving coordiantes to somewhere
	if (ft_validate_coordinate())
		return ();
	else
	{
		tetro->x[0] + 1;
		if (i > x_max)
		{
			x = 0;
			j++;
		}
		if (j > y_max)
			return (make grid bigger)
		ft_change_coordinates()

	}
}
*/
int ft_validate_coordinate(t_tetro *tetro, int **grid)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (tetro->y[i] < 0 || tetro->x[i] < 0)
		{
//			printf("x tai y < 0 [%d,%d] [%d,%d] [%d,%d] [%d,%d]\n", tetro->x[0], tetro->y[0], tetro->x[1], tetro->y[1], tetro->x[2], tetro->y[2], tetro->x[3], tetro->y[3]);
			return (0);
		}
		if (tetro->y[i] == GRID_SIZE || tetro->x[i] == GRID_SIZE)
		{
//			printf("yli gridin [%d,%d] [%d,%d] [%d,%d] [%d,%d]\n", tetro->x[0], tetro->y[0], tetro->x[1], tetro->y[1], tetro->x[2], tetro->y[2], tetro->x[3], tetro->y[3]);
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (grid[tetro->y[i]][tetro->x[i]] == 1)
		{
//			printf("menee paallekkain [%d,%d] [%d,%d] [%d,%d] [%d,%d]\n", tetro->x[0], tetro->y[0], tetro->x[1], tetro->y[1], tetro->x[2], tetro->y[2], tetro->x[3], tetro->y[3]);
			return (0);
		}
		i++;
	}
	return (1);
}

/*
**	Some really confusing syntax here might be faster this way
**	     	   *((*tetro)->x + i)
**	 dereference|struct*|int  |i == index on structs int array
**	 to integer |deref  |array|
**
**	ALTERNATIVE: (*tetro)->x[i] 
*/

int	ft_move_coordinate(t_tetro **tetro, int x, int y, int **grid)
{
	int i;
	int x_count;
	int y_count;
	int x_save;
	int y_save;

	i = 0;
	x_count = x - *(*tetro)->x;
	y_count = y - *(*tetro)->y;
	x_save = *(*tetro)->x;
	y_save = *(*tetro)->y;
	while (i < 4)
	{
		*((*tetro)->x + i) += x_count;
		*((*tetro)->y + i) += y_count;
		i++;
	}
	if (grid)
	{
		if (!(ft_validate_coordinate(*tetro, grid)))
		{
			return (0);
		}
	}
	return (1);
}


// KOKONAAN TURHA ??
/*int	**ft_generate_answer(t_tetro *s_tetro, int **grid)
{
	int x = 0;
	int y = 0;
	int i = 0;
	t_tetro *head;

	head = s_tetro;
	while (s_tetro != NULL)
	{
		printf("loop#%d x = %d y = %d\n", i, x , y);
		if (ft_move_coordinate(&s_tetro, x, y, grid))
		{
			ft_flip_grid(s_tetro, grid);
			s_tetro = s_tetro->next;
			x = 0;
			y = 0;
		}
		else
		{
			x++;
			if (x == GRID_SIZE)
			{
				x = 0;
				y++;
			}
			if (y == GRID_SIZE)
			{
				if (ft_move_1(&s_tetro, grid))
				{
					ft_generate_answer(s_tetro->next, grid);
				}
				else
				{
					GRID_SIZE++;
					printf("grid made bigger\n");
					grid = ft_make_grid(grid);
					s_tetro = head;
				}
			}
		}
		i++;
	}
	ft_generate_answer(head, grid);
	return (grid);
}*/

// TAMAKIN TURHA ??
/*int	**ft_place_block(t_tetro *s_tetro, int **grid)
{
	int x = 0;
	int y = 0;
	int i = 0;
	t_tetro *head;

	head = s_tetro;
	while (s_tetro != NULL)
	{
		printf("loop#%d x = %d y = %d\n", i, x , y);
		if (ft_move_coordinate(&s_tetro, x, y, grid))
		{
			ft_flip_grid(s_tetro, grid);
			s_tetro = s_tetro->next;
			x = 0;
			y = 0;
		}
		else
		{
			x++;
		}
		if (x == GRID_SIZE)
		{
			x = 0;
			y++;
		}
		if (y == GRID_SIZE)
		{
			GRID_SIZE++;
			grid = ft_make_grid(grid);
			s_tetro = head;
			y = 0;
		}
		i++;
	}
	return (grid);
}*/

t_tetro	*ft_reset_coordinates(t_tetro **tetro, int **grid)
{
	t_tetro *head;
	while ((*tetro)->prev)
	{
		(*tetro) = (*tetro)->prev;
	}
	head = *tetro;
	while((*tetro))
	{
		ft_move_coordinate(tetro,  0, 0, grid);
		(*tetro) = (*tetro)->next;
	}
	return (head);
}

int	ft_move_1(t_tetro **tetro, int **grid)
{
	int x_origin;
	int y_origin;
	int	line;
	int x_place;
	int	i = 0;

	x_origin = *(*tetro)->x;
	x_place = x_origin;
	y_origin = *(*tetro)->y;
	printf("liikutellaan palikkaa %c move1:ssa\n", 'A' + (*tetro)->letter);
	while ((*tetro)->y[0] < GRID_SIZE)
	{
		x_place++;
		if (ft_move_coordinate(tetro, x_place, (*tetro)->y[0], grid))
		{
//			printf("liikutellaan oikeelle...\n");
			return (1);
		}
//		printf("x_place is %d\n", x_place);
		/*		while ((*tetro)->x[i] <= 3)
		{
			if (x_place >= GRID_SIZE)
			{
//				printf("nyt taalla\n");
				if (ft_move_coordinate(tetro, 0, (*tetro)->y[0] + 1, grid))
				{
					return (1);
				}
				x_place = 0;
			}
			i++;
		}*/
		if (x_place >= GRID_SIZE)
		{
//			printf("nyt taalla\n");
			if (ft_move_coordinate(tetro, 0, (*tetro)->y[0] + 1, grid))
			{
//				printf("liikutellaam alaspain...\n");
//				printf("move1 seuraavalle riville (%d,%d) (%d,%d) (%d,%d) (%d,%d)\n", (*tetro)->x[0], (*tetro)->y[0], (*tetro)->x[1], (*tetro)->y[1], (*tetro)->x[2], (*tetro)->y[2], (*tetro)->x[3], (*tetro)->y[3]);
				return (1);
			}
			x_place = 0;
		}
	}
//	printf("ei loytyny paikkaa move1:lla...\n");
	return (0);
}

int	ft_recursive(t_tetro **s_tetro, int **grid)
{
	int grid_save;
	static int n = 0;
	static int	loop = 1;
//	static char	palikka = 'A';

	printf("\033[33mrundi %d ---------------------------------------------- \033[0m\n", loop++);
	n++;
	grid_save = GRID_SIZE;
//	printf("%c\n", 'A' + (*s_tetro)->letter);
//ft_puterr(0);
	
//	if (!(*s_tetro)->next)
//	{
//		ft_puterr(6);
//		printf("\033[01;32mvika palikka %d osui kohdalleen\033[0m\n", palikka);
//		printf("taa oli vika palikka\n");
//		return (n);
//	}
	printf("\033[01;36mpalikka %c starttaa rundin\033[0m\n", 'A' + (*s_tetro)->letter);
//	printf("\033[01;36mpalikka %c starttaa rundin\033[0m\n", palikka);
	if (!ft_validate_coordinate(*s_tetro, grid))
//	if (!ft_validate_coordinate(*s_tetro, grid) && *(*s_tetro)->y < GRID_SIZE)
	{
//	ft_puterr(1);
//		printf("\033[01;36mpalikkaa %c liikutellaan gridin sisalla, kunnes validi\033[0m\n", 'A' + (*s_tetro)->letter);
//		printf("\033[01;36mpalikkaa %c liikutellaan gridin sisalla, kunnes validi\033[0m\n", palikka);
		ft_move_1(s_tetro, grid);
	}
//	printf("*(*s_tetro)->x on: %d\n", *(*s_tetro)->x);
//	printf("*(*s_tetro)->y on: %d\n", *(*s_tetro)->y);
//	printf("ulos whilesta koordinaateilla: [%d,%d] [%d,%d] [%d,%d] [%d,%d]\n", (*s_tetro)->x[0], (*s_tetro)->y[0], (*s_tetro)->x[1], (*s_tetro)->y[1], (*s_tetro)->x[2], (*s_tetro)->y[2], (*s_tetro)->x[3], (*s_tetro)->y[3]);
//	printf("GRID_SIZE: %dx%d (x_max %d, y_max %d)\n", GRID_SIZE, GRID_SIZE, GRID_SIZE - 1, GRID_SIZE - 1);
	if (*(*s_tetro)->y >= GRID_SIZE && !(*s_tetro)->prev)
	{
//	ft_puterr(2);
		GRID_SIZE++;
		printf("\033[01;35mgrid made bigger (now %dx%d)\033[0m\n", GRID_SIZE, GRID_SIZE);
		grid = ft_make_grid(grid);
//		printf("%d", (*s_tetro)->letter);
		*s_tetro = ft_reset_coordinates(s_tetro, grid);
//		palikka = 'A';
		ft_recursive(s_tetro, grid);
	}
	else if (*(*s_tetro)->y >= GRID_SIZE)
	{
//	ft_puterr(3);
		printf("\033[01;31mpalikka %c move1 FAIL [%d,%d] [%d,%d] [%d,%d] [%d,%d]\033[0m\n", 'A' + (*s_tetro)->letter, (*s_tetro)->x[0], (*s_tetro)->y[0], (*s_tetro)->x[1], (*s_tetro)->y[1], (*s_tetro)->x[2], (*s_tetro)->y[2], (*s_tetro)->x[3], (*s_tetro)->y[3]);
//		printf("\033[01;31mpalikka %c meni yli [%d,%d] [%d,%d] [%d,%d] [%d,%d]\033[0m\n", palikka, (*s_tetro)->x[0], (*s_tetro)->y[0], (*s_tetro)->x[1], (*s_tetro)->y[1], (*s_tetro)->x[2], (*s_tetro)->y[2], (*s_tetro)->x[3], (*s_tetro)->y[3]);
		ft_flip_grid((*s_tetro)->prev, grid);
		if (ft_move_1(&(*s_tetro)->prev, grid))
		{
			printf("\033[01;32mpalikka %c move1 SUCCESS [%d,%d] [%d,%d] [%d,%d] [%d,%d]\033[0m\n", 'A' + ((*s_tetro)->prev)->letter, (*s_tetro)->prev->x[0], (*s_tetro)->prev->y[0], (*s_tetro)->prev->x[1], (*s_tetro)->prev->y[1], (*s_tetro)->prev->x[2], (*s_tetro)->prev->y[2], (*s_tetro)->prev->x[3], (*s_tetro)->prev->y[3]);
//			printf("\033[01;32mpalikan %c liikuttaminen onnistui [%d,%d] [%d,%d] [%d,%d] [%d,%d]\033[0m\n", palikka -1, (*s_tetro)->prev->x[0], (*s_tetro)->prev->y[0], (*s_tetro)->prev->x[1], (*s_tetro)->prev->y[1], (*s_tetro)->prev->x[2], (*s_tetro)->prev->y[2], (*s_tetro)->prev->x[3], (*s_tetro)->prev->y[3]);
//			printf("%d\n", (*s_tetro)->y[0]);
			ft_flip_grid((*s_tetro)->prev, grid);
			ft_move_coordinate(s_tetro, 0, 0, grid);
			printf("\033[01;36mlahetetaan takas palikka %c\033[0m\n", 'A' + (*s_tetro)->letter);
			ft_recursive(s_tetro, grid);
		}
		else
		{
			printf("\033[01;31mpalikka %c move1 FAIL [%d,%d] [%d,%d] [%d,%d] [%d,%d]\033[0m\n", 'A' + ((*s_tetro)->prev)->letter, (*s_tetro)->prev->x[0], (*s_tetro)->prev->y[0], (*s_tetro)->prev->x[1], (*s_tetro)->prev->y[1], (*s_tetro)->prev->x[2], (*s_tetro)->prev->y[2], (*s_tetro)->prev->x[3], (*s_tetro)->prev->y[3]);
		// ALEMPI ON VAARIN	
		//	printf("\033[01;31mpalikkaa %c ei voi liikuttaa... [%d,%d] [%d,%d] [%d,%d] [%d,%d]\033[0m\n", palikka -1, (*s_tetro)->x[0], (*s_tetro)->y[0], (*s_tetro)->x[1], (*s_tetro)->y[1], (*s_tetro)->x[2], (*s_tetro)->y[2], (*s_tetro)->x[3], (*s_tetro)->y[3]);
			ft_move_coordinate(s_tetro, 0, 0, grid);
//			palikka--;
			printf("\033[01;36mlahetetaan takas edellinen palikka %c\033[0m\n", 'A' + ((*s_tetro)->prev)->letter);
			ft_recursive(&(*s_tetro)->prev, grid);
		}
	}
	else if ((*s_tetro)->next)
	{
//		ft_puterr(4);
		printf("\033[01;32mpalikka %c osui kohdalleen [%d,%d] [%d,%d] [%d,%d] [%d,%d]\033[0m\n", 'A' + (*s_tetro)->letter, (*s_tetro)->x[0], (*s_tetro)->y[0], (*s_tetro)->x[1], (*s_tetro)->y[1], (*s_tetro)->x[2], (*s_tetro)->y[2], (*s_tetro)->x[3], (*s_tetro)->y[3]);
//		printf("\033[01;32mpalikka %c osui kohdalleen [%d,%d] [%d,%d] [%d,%d] [%d,%d]\033[0m\n", palikka++, (*s_tetro)->x[0], (*s_tetro)->y[0], (*s_tetro)->x[1], (*s_tetro)->y[1], (*s_tetro)->x[2], (*s_tetro)->y[2], (*s_tetro)->x[3], (*s_tetro)->y[3]);
//		if ((*s_tetro)->next)
//		{
//			ft_puterr(5);
//			printf("ei ollu vika palikka\n");
//		}
//		printf("flipataan ykkoset ja mennaan back\n");
		ft_flip_grid((*s_tetro), grid);
		printf("\033[01;36mlahetetaan takas seuraava palikka %c\033[0m\n", 'A' + ((*s_tetro)->next)->letter);
		ft_recursive(&(*s_tetro)->next, grid);
	}
	else
//	if (!(*s_tetro)->next)
//	{
//		ft_puterr(6);
//		printf("\033[01;32mvika palikka %d osui kohdalleen\033[0m\n", palikka);
//		printf("taa oli vika palikka\n");
//		return (n);
//	}
//	ft_puterr(8);
	printf("\033[01;32mvika paliKKa %c osui kohtaan  [%d,%d] [%d,%d] [%d,%d] [%d,%d]\033[0m\n", 'A' + (*s_tetro)->letter, (*s_tetro)->x[0], (*s_tetro)->y[0], (*s_tetro)->x[1], (*s_tetro)->y[1], (*s_tetro)->x[2], (*s_tetro)->y[2], (*s_tetro)->x[3], (*s_tetro)->y[3]);
//	printf("\033[01;32mvika palikka %c osui kohtaan [%d,%d] [%d,%d] [%d,%d] [%d,%d]\033[0m\n", palikka++, (*s_tetro)->x[0], (*s_tetro)->y[0], (*s_tetro)->x[1], (*s_tetro)->y[1], (*s_tetro)->x[2], (*s_tetro)->y[2], (*s_tetro)->x[3], (*s_tetro)->y[3]);
//	write(1, "ei mee mihkaan looppiin\n", 24);
//	exit (0);
	return (n);
}
