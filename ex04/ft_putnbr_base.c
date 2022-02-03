/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:12:12 by asousa-l          #+#    #+#             */
/*   Updated: 2022/01/26 20:21:30 by asousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <limits.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_checkbase(char *base)
{
	int	i;
	int	j;

	if (base[0] == '\0' || base[1] == 1)
	{
		return (0);
	}
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] <= 32 || base[i] == 127 || base[i] == 45 || base[i] == 43)
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		len;
	long	n;

	n = nbr;
	len = ft_checkbase(base);
	if ((len) >= 2)
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
		}
		if (n < len)
		{
			ft_putchar(base[n]);
		}
		if (n >= len)
		{
			ft_putnbr_base((n / len), base);
			ft_putnbr_base((n % len), base);
		}
	}
}
/*
int	main(void)
{
	ft_putnbr_base(-123456, "helo");
	printf("\n");
	fflush(stdout);
	ft_putnbr_base(INT_MIN, "0123456789");
	printf("\n");
	fflush(stdout);
	ft_putnbr_base(INT_MAX, "0123456789abcdef");
}*/