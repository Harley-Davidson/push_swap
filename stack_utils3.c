/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:00:28 by mvoloshy          #+#    #+#             */
/*   Updated: 2024/05/30 17:00:30 by mvoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_node	*get_last_node(t_node *node)
{
	if (node == NULL)
		return (NULL);
	while (node->next != NULL)
		node = node->next;
	return (node);
}

t_node	*get_cheapest_node(t_node **stack)
{
	t_node	*node;

	node = *stack;
	if (node == NULL)
		return (NULL);
	while (node != NULL)
	{
		if (node->is_cheapest)
			return (node);
		node = node->next;
	}
	return (NULL);
}

t_node	*get_smallest_node(t_node **stack)
{
	int		smallest;
	t_node	*node;
	t_node	*smallest_node;

	node = *stack;
	if (node == NULL)
		return (NULL);
	smallest = INT_MAX;
	while (node != NULL)
	{
		if (node->value < smallest)
		{
			smallest = node->value;
			smallest_node = node;
		}
		node = node->next;
	}
	return (smallest_node);
}

t_node	*get_biggest_node(t_node **stack)
{
	int		biggest;
	t_node	*node;
	t_node	*biggest_node;

	node = *stack;
	if (node == NULL)
		return (NULL);
	biggest = INT_MIN;
	while (node != NULL)
	{
		if (node->value > biggest)
		{
			biggest = node->value;
			biggest_node = node;
		}
		node = node->next;
	}
	return (biggest_node);
}
