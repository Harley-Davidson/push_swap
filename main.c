/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:35:59 by mvoloshy          #+#    #+#             */
/*   Updated: 2024/05/04 16:36:01 by mvoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**offset_argv(int argc, char **argv)
{
	int		i;

	i = 0;
	while(i < argc)
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
	int		num;
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
		if (ft_atoi_long(s) > INT_MAX || ft_atoi_long(s) < INT_MIN)
			return (1);
		argv++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_node  *a;
	t_node  *b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (0);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv = offset_argv(argc, argv);
	if (is_arg_error(argv))
	{
		ft_printf("Error\n");
		return (1);
	}
	init_stack(&a, argv, argc);
	print_stack(&a);
	push_swap(&a, &b);
	print_stack(&a);
	free_stacks(&a, &b);
}