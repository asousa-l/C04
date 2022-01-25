/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 09:16:45 by asousa-l          #+#    #+#             */
/*   Updated: 2022/01/24 09:51:03 by asousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	s;
	int	tot;

	i = 0;
	s = 1;
	tot = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (i > 3)
		return (0);
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		tot = (str[i] - '0') + (tot * 10);
		i++;
	}
	return (tot * s);
}
/*
int	main(void)
{
	printf("%d\n", ft_atoi("      	---+--+2147--+-ab567"));
}
*/