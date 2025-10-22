/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nqueens2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 22:03:06 by valero            #+#    #+#             */
/*   Updated: 2025/10/21 22:53:40 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static void	nqueens(int start, int len, int *board);
static void	init_board(int *board, int len);
static void	put_board(int *board, int len);
static int	validate(int start, int *board, int row);

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	int	n = atoi(argv[1]);
	int	board[n];
	init_board(board, n);
	nqueens(0, n, board);
}

static void	nqueens(int start, int len, int *board)
{
	if (start == len)
		put_board(board, len);
	else
	{
		int	row = -1;
		while (++row < len)
		{
			if (validate(start, board, row))
			{
				board[start] = row;
				nqueens(start + 1, len, board);
				board[start] = -1;
			}
		}
	}
}

static void	init_board(int *board, int len)
{
	while (--len >= 0)
		board[len] = -1;
}

static void	put_board(int *board, int len)
{
	int	i;

	i = -1;
	while (++i < len)
	{
		fprintf(stdout, "%d", board[i]);
		if (i + 1 < len)
			fprintf(stdout, " ");
	}
	fprintf(stdout, "\n");
}

static int	is_same_diagonal(int curr_x, int curr_y, int new_x, int new_y)
{
	int	delta_x = curr_x - new_x;
	if (delta_x < 0)
		delta_x = -delta_x;
	int	delta_y = curr_y - new_y;
	if (delta_y < 0)
		delta_y = -delta_y;
	return (delta_x == delta_y);
}

static int	validate(int start, int *board, int row)
{
	int	curr_row = -1;
	while (++curr_row < start)
		if (board[curr_row] == row || is_same_diagonal(curr_row, board[curr_row], start, row))
			return (0);
	return (1);
}
