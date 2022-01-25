/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:12:12 by asousa-l          #+#    #+#             */
/*   Updated: 2022/01/25 18:03:27 by asousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_size_base(char *base, int i)
{
	while (base[i] != '\0')
		i++;
	if (i < 2)
		return (0);
	return (i);
}

int	ft_signal(char *base, int i)
{
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == '\t' || \
			base[i] == '\n' || base[i] == '\v' || base[i] == '\r' || \
			base[i] == '\f' || base[i] == ' ')
			return (0);
		i++;
	}
	return (1);
}

int	ft_equal(char *base, int i, int c, int b)
{
	while (i < c - 1)
	{
		if (base[i] == base[b])
			break ;
		else
		{
			if (b < 5)
				b++;
			else
			{
				i++;
				b = i + 1;
			}
		}
	}
	if (i < c - 1)
		return (0);
	return (1);
}

void	ft_putnbr(int nbr, char *base, int c)
{
	if (nbr == -2147483648)
	{
		ft_putnbr(nbr / c, base, c);
		write(1, &(base[-(nbr % c)]), 1);
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-nbr, base, c);
	}
	else
	{
		if (nbr > c)
		{
			ft_putnbr((nbr / c), base, c);
		}
		write(1, &(base[nbr % c]), 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;
	int	b;
	int	c;

	i = 0;
	b = 1;
	c = ft_size_base(base, i);
	ft_equal(base, i, c, b);
	if ((ft_size_base(base, i) != 0) && (ft_signal(base, i) != 0) && \
			(ft_equal(base, i, c, b) != 0))
		ft_putnbr(nbr, base, c);
}
/*
int	main()
{
	int	nbr;
	char	base[] = "poneyvif";

	nbr = 199;
	ft_putnbr_base(nbr, base);
}
*/
