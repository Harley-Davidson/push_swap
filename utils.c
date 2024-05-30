/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:36:20 by mvoloshy          #+#    #+#             */
/*   Updated: 2024/05/04 16:36:21 by mvoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi_long(const char *nptr)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while ((*nptr == 32) || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = sign * -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result * sign);
}

char	**offset_argv(int argc, char **argv)
{
	int		i;

	if (argc == 2)
		return (argv);
	i = 0;
	while (i < argc)
	{
		argv[i] = argv[i + 1];
		i++;
	}
	return (argv);
}

int	is_duplicated(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_strncmp(argv[i], argv[j], 15) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_arg_error(char **argv)
{
	long	num;
	char	*s;

	if (is_duplicated(argv))
		return (1);
	while (*argv)
	{
		s = *argv;
		if (ft_strlen(s) > 11 || (*s != '-' && *s != '+' && !ft_isdigit(*s)))
			return (1);
		while (*(++s))
		{
			if (!ft_isdigit(*s))
				return (1);
		}
		s = *argv;
		num = ft_atoi_long(s);
		if (num > INT_MAX || num < INT_MIN)
			return (1);
		argv++;
	}
	return (0);
}
