/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 09:16:45 by asousa-l          #+#    #+#             */
/*   Updated: 2022/01/26 20:21:56 by asousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	s;
	int	tot;

	i = 0;
	s = 0;
	tot = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ' || \
			str[i] == '\f' || str[i] == '\v' || str[i] == '\n')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		tot = (str[i] - '0') + (tot * 10);
		i++;
	}
	if ((s % 2) != 0)
		tot = -tot;
	return (tot);
}
/*
int	main(void)
{
	int		mine;
	char	str[];
   
	str = "  ---1234ab567";

	mine = ft_atoi(str);
	printf("mine: %d\n", mine);
}*/
