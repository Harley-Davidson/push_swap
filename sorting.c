/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:35:38 by mvoloshy          #+#    #+#             */
/*   Updated: 2024/05/04 16:35:41 by mvoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node **a)
{
	t_node	*node;

	if (a == NULL || *a == NULL)
		return (0);
	node = *a;
	while (node->next)
	{
		if (node->value > (node->next)->value)
			return (0);
		node = node->next;
	}
	return (1);
}

/*
 * 	~If the 1* is the biggest, ra (biggest to bottom)
 * 	~If the 2* is the biggest, rra (biggest to bottom)
 * 	~Now i have forcefully the Biggest at the bottom
 * 		so i just chek 1° and 2°
*/
void	sort_three(t_node **a, int size)
{
	if (size == 3)
	{
		if ((*a)->value > ((*a)->next)->value
			&& (*a)->value > (((*a)->next)->next)->value)
			rotate(a, "ra\n");
		else if (((*a)->next)->value > (*a)->value
			&& ((*a)->next)->value > (((*a)->next)->next)->value)
			reverse_rotate(a, "rra\n");
	}
	if ((*a)->value > ((*a)->next)->value)
		swap(a, "sa\n");
}

void	sort_five(t_node **a, t_node **b, int size)
{
	t_node	*smallest;

	if (is_sorted(a))
		return ;
	while (size-- > 3)
	{
		set_position(a);
		smallest = get_smallest_node(a);
		if (smallest->is_above_med)
			while (*a != smallest)
				rotate(a, "ra\n");
		else
			while (*a != smallest)
				reverse_rotate(a, "rra\n");
		push(a, b, "pb\n");
	}
	sort_three(a, 3);
	while (*b != NULL)
		push(b, a, "pa\n");
}
