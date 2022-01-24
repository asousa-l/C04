/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:42:20 by asousa-l          #+#    #+#             */
/*   Updated: 2022/01/24 21:11:40 by asousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_check_base(char *base)
{
	int	i;

	i = 0;
	while (*base != '\0')
	{
		if (base[i] == signs() || base[i] == base[i + 1] || base[i] == spaces())
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

int	ft_n(char str, char *base, int result, int tot)
{
	int	i;

	i = 0;
	while (base[i] !+ '\0')
	{
		if (str == base[i])
			return (tot + (result * i));
		i++;
	}
	return (tot);
}

int	ft_base(char c, char *base)
{
	int	n;

	n = 0;
	if (n == spaces() || n == signs())
		return (1);
	while (base[n] != '\0')
	{
		if (base[n] == c)
			return (2);
		n++;
	}
	return (0);
}

int	ft_atoi_maker(char *str, char *base, int i, int a)
{
	int	s;
	int	tot;
	int	result;

	a--;
	s = 1;
	tot = 0;
	result = 1;
	while ((str[a] >= 0))
	{
		if (str[a] == '-')
		{
			s = s * -1;
		}	
		if (ft_base(str[a], base) == 2)
		{
			tot = ft_n(str[a], base, result, tot);
			result = result * i;
		}
		a--;
	}
	return (tot * s);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	if (ft_check_base(base) == 0)
		return (0);
	while (base[i] != '\0')
		i++;
	while (str[a] == spaces())
		a++;
	while (str[a] == signs())
		a++;
	while (str[a] >= '0' && str[a] <= '9')
		a++;
	return (ft_atoi_maker(str, base, i, a));
}
