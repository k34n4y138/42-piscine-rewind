/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoumen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:04:52 by zmoumen           #+#    #+#             */
/*   Updated: 2022/05/13 17:04:56 by zmoumen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

typedef unsigned long long int	t_ulli;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	print_hex(t_ulli nb, int itrno)
{
	if (itrno > 0)
	{
		print_hex(nb / 16, itrno - 1);
		ft_putchar("0123456789abcdef"[nb % 16]);
	}
}

void	process_line(char **addr, unsigned int size)
{
	char			string[17];
	unsigned int	str_idx;

	str_idx = 0;
	while (str_idx < 16)
	{
		if (size > (unsigned int)0)
		{
			print_hex((t_ulli)(*addr)[0], 2);
			if ((*addr)[0] > 31 && (*addr)[0] < 127)
				string[str_idx++] = (*addr)[0];
			else
				string[str_idx++] = '.';
			(*addr)++;
			size--;
		}
		else
		{
			ft_putstr("  ");
			string[str_idx++] = 0;
		}
		if (str_idx % 2 == 0)
			ft_putstr(" ");
	}
	ft_putstr(string);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char	*addr_copy;

	addr_copy = (char *)addr;
	while (size > (unsigned int)0)
	{
		print_hex((t_ulli)addr_copy, 15);
		ft_putstr(": ");
		process_line(&addr_copy, size);
		ft_putchar('\n');
		if (size > 16)
			size -= 16;
		else
			size -= size;
	}
	return (addr);
}

int	main(void)
{
	char	*bloob;

	bloob = "I hope I made myself clear\xff\x10\x0a\x7e\x7f\0";
	ft_print_memory(bloob,32);
	return (0);
}
