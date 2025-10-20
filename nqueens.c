/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nqueens.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:46:03 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/20 15:54:32 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static void	n_queens(int n, int *tab, int column);
static int	validate(int n, int *tab, int row, int column);
static void	print_tab(int n, int *tab);
void		init_array(int *tab, int size);

int	main(int argc, char **argv)
{
	int	n;

	if (argc != 2)
		return (1);
	n = atoi(argv[1]);
	int	tab[n];
	init_array(tab, n);
	n_queens(n, tab, 0);
}

void	init_array(int *tab, int size)
{
	int	i;

	i = -1;
	while (++ i < size)
		tab[i] = -1;
}



static void	n_queens(int n, int *tab, int column)
{
	int	row;

	if (column == n)
	{
		print_tab(n, tab);
		return ;
	}
	row = -1;
	while (++row < n)
	{
		if (validate(n, tab, row, column))
		{
			tab[column] = row;
			n_queens(n, tab, column + 1);
		}
	}

}

static int	is_same_diagonal(int last_x, int last_y, int curr_x, int curr_y);

static int	validate(int n, int *tab, int row, int column)
{
	int	i;

	i = -1;
	(void)n;
	while (++i < column)
		if ((tab[i] == row || is_same_diagonal(i, tab[i], column, row)))
			return (0);
	return (1);
}

static int	is_same_diagonal(int last_x, int last_y, int curr_x, int curr_y)
{
	int	delta_x;
	int	delta_y;

	delta_x = last_x - curr_x;
	if (delta_x < 0)
		delta_x = -delta_x;
	delta_y = last_y - curr_y;
	if (delta_y < 0)
		delta_y = -delta_y;
	return (delta_x == delta_y);
}

static void	print_tab(int n, int *tab)
{
	int	i;

	i = -1;
	while (++i < n)
		printf("%d", tab[i]);
	printf("\n");
}
