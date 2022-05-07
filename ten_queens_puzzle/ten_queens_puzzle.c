/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ten_queens_optimized.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoumen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 01:53:46 by zmoumen           #+#    #+#             */
/*   Updated: 2022/05/07 02:30:15 by zmoumen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#ifndef SIZE
# define SIZE 4
#endif

void	ft_putnbr(int nbr)
{
	char	prnt;

	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		prnt = 48 + (nbr % 10);
	}
	else
	{
		prnt = 48 + nbr;
	}
	write(1, &prnt, 1);
}

int	queen_is_safe(char arr[SIZE][SIZE], int r, int c, int *counts)
{
	int	x;
	int	y;
	int	z;

	x = r;
	y = c;
	z = c;
	while (--x >= 0)
		if (arr[x][c] == 'Q' || (--y >= 0 && arr[x][y] == 'Q')
		|| (++z < SIZE && arr[x][z] == 'Q'))
			return (0);
	if (r == SIZE - 1)
	{
		while (++x < SIZE)
		{
			y = -1;
			while (++y < SIZE)
				if (arr[x][y] == 'Q')
					ft_putnbr(y);
		}
		write(1, "\n", 1);
		(*counts)++;
	}
	return (1);
}

void	n_queen_puzzle(char arr[SIZE][SIZE], int row, int *counts)
{
	int	col;

	col = 0;
	while (col < SIZE && row < SIZE)
	{
		arr[row][col] = 'Q';
		if (queen_is_safe(arr, row, col, counts))
			n_queen_puzzle(arr, row + 1, counts);
		arr[row][col++] = 0;
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	arr[SIZE][SIZE];
	int		x;
	int		y;
	int		counts;

	x = 0;
	y = 0;
	while (x < SIZE)
	{
		while (y < SIZE)
			arr[x][y++] = 0;
		x++;
	}
	counts = 0;
	n_queen_puzzle(arr, 0, &counts);
	return (counts);
}

int	main(void)
{
	int	count;

	count = ft_ten_queens_puzzle();
	ft_putnbr(count);
	write(1, "\n", 1);
	return (0);
}
