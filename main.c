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

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

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
	print_stack(&a, "a");
	push_swap(&a, &b);
	print_stack(&a, "a");
	free_stacks(&a, &b);
}