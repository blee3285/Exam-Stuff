/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 18:46:46 by blee              #+#    #+#             */
/*   Updated: 2017/05/30 15:28:54 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_hex(unsigned char c)
{
	int a;
	int b;

	a = c / 16;
	b = c % 16;
	if (a < 10)
		ft_putchar(a + '0');
	else
		ft_putchar(a - 10 + 'a');
	if (b < 10)
		ft_putchar(b + '0');
	else
		ft_putchar(b - 10 + 'a');
}

void	print_bits(unsigned char *bits, size_t i, size_t size)
{
	size_t	max = i + 16;

	while ((i < max) && (i < size))
	{
		print_hex(bits[i]);
		i++;
		if (i % 2 == 0)
			ft_putchar(' ');
	}
	while ((i < max) && (i >= size))
	{
		ft_putchar(' ');
		ft_putchar(' ');
		i++;
		if (i % 2 == 0)
			ft_putchar(' ');
	}
}

void	print_data(unsigned char *bits, size_t i, size_t size)
{
	size_t max;

	max = i + 16;
	while ((i < max) && (i < size))
	{
		if (bits[i] > 31 && bits[i] < 127)
			ft_putchar(bits[i]);
		else
			ft_putchar('.');
		i++;
	}
	ft_putchar('\n');
}

void	print_memory(const void *addr, size_t size)
{
	unsigned char	*bits;
	size_t			i;
	
	bits = (unsigned char *)addr;
	i = 0;

	while (i < size)
	{
		print_bits(bits, i, size);
		print_data(bits, i, size);
		i += 16;
	}
}

int	main(void)
{
	int	tab[10] = {0, 23, 150, 255,
					12, 16, 21, 42};
	char str[] = "ABCDEFG";
	print_memory(tab, sizeof(tab));
	ft_putchar('\n');
	print_memory(str, sizeof(str));
	return (0);
}
