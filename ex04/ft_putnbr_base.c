/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:12:12 by asousa-l          #+#    #+#             */
/*   Updated: 2022/01/24 18:41:20 by asousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_check_base(char *base)
{
	int	i;

	i = 0;
	while (*base != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == base[i + 1])
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

void	ft_putnbr(int nbr, char *base, int i)
{
	unsigned int	n;
	char			c;

	if (nbr < 0)
	{
		write(1, '-', 1);
		n = nbr * (-1);
	}
	else
		n = nbr;
	if (n >= (unsigned int)i)
		ft_putnbr(n / i, base, i);
	c = base[n % i];
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;

	i = 0;
	if (ft_check_base(base) == 1)
	{
		while (base[i] != '\0')
			i++;
		ft_putnbr(nbr, base, i);
	}
}
