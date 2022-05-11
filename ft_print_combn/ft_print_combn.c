/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoumen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:38:06 by zmoumen           #+#    #+#             */
/*   Updated: 2022/04/28 00:16:38 by zmoumen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	init_arr(int arr[], int n)
{
	int	i;

	i = 0;
	while (--n >= 0)
		arr[n] = i++;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_arr(int arr[], int n)
{
	int	max;
	int	i;

	i = n;
	max = arr[i - 1];
	while (--i >= 0)
		ft_putchar(arr[i] + 48);
	if (max < 10 - n)
		write(1, ", ", 2);
}

void	increment_arr(int arr[], int n)
{
	int	itr;
	int	max;

	itr = 0;
	max = 9;
	while (arr[itr] == max && max >= 0 && itr < n)
	{
	itr++;
	max--;
	}
	while (itr >= 0)
	{
		arr[itr]++;
		if (itr)
			arr[itr - 1] = arr[itr];
		itr--;
	}
}

void	ft_print_combn(int n)
{
	int	arr[10];

	if (n <= 0 || n >= 10)
		return ;
	init_arr(arr, n);
	print_arr(arr, n);
	while (arr[n - 1] < 10 - n)
	{
		increment_arr(arr, n);
		print_arr(arr, n);
	}
}

#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac > 1)
		ft_print_combn(atoi(av[1]));
	return (0);
}
