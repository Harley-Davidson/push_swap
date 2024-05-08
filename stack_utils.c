/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:35:48 by mvoloshy          #+#    #+#             */
/*   Updated: 2024/05/04 16:35:50 by mvoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *get_last_node(t_node *node)
{
	if (node == NULL)
		return (NULL);
	while (node->next != NULL)
		node = node->next;
	return (node);
}

void add_node(t_node **stack, int arg)
{
	t_node  *last_node;
	t_node  *new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->value = arg;
	last_node = get_last_node(*stack);
	if (last_node == NULL)
		*stack = new_node;
	else
	{
		new_node->prev = last_node;
		last_node->next = new_node;
	}
}

void	init_stack(t_node **a, char **argv, int	argc)
{
	int		i;

	if (argv == NULL || a == NULL)
		return ;
	i = 0;
	while (argv[i])
		add_node(a, ft_atoi_long(argv[i++]));
	if (argc == 2)
	{
		i = 0;
		while (argv[i] != NULL)
			free(argv[i++]);
		free(argv);
	}
}

int	get_node_cnt(t_node **stack)
{
	int		i;
	t_node	*a;

	if (stack == NULL)
		return (0);
	i = 0;
	a = *stack; 
	while (a)
	{
		a = (a)->next;
		i++;
	}
	return (i);
}

void	free_stacks(t_node **a, t_node **b)
{
	t_node	*tmp;

	tmp = *a;
	while (tmp)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
	if (*b == NULL)
		return ;
	tmp = *b;
	while (tmp)
	{
		tmp = (*b)->next;
		free(*b);
		*b = tmp;
	}
}

void	print_stack(t_node **node)
{
	t_node  *buf;
	
	if (node == NULL || *node == NULL)
		return ;
	buf = *node;
	while (buf != NULL )
	{
		ft_putnbr_fd(buf->value, 1);
		ft_putchar_fd(' ', 1);
		buf = buf->next;
	}
	ft_putstr_fd("\n", 1);
}