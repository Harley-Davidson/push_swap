/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:07:29 by mvoloshy          #+#    #+#             */
/*   Updated: 2024/04/30 15:07:34 by mvoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stacks_rotation(t_node **a, t_node **b,
								t_node *cheapest_node, char *func)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
	{
		if (ft_strncmp(func, "rr\n", 3) == 0)
			rotate_both(a, b, func);
		else if (ft_strncmp(func, "rrr\n", 4) == 0)
			reverse_rotate_both(a, b, func);
	}
	set_position(a);
	set_position(b);
}

void	finish_rotation(t_node **stack, t_node *top_node, char *stack_name)
{
	while (*stack != top_node)
	{
		ft_putstr_fd("r", 1);
		if (top_node->is_above_med)
			rotate(stack, "");
		else
		{
			reverse_rotate(stack, "");
			ft_putstr_fd("r", 1);
		}
		ft_putstr_fd(stack_name, 1);
		ft_putstr_fd("\n", 1);
	}
}

static void	move_nodes(t_node **a, t_node **b)
{
	t_node	*c;
	char	*func;

	c = get_cheapest_node(b);
	if (c->is_above_med && (c->target_node)->is_above_med)
		stacks_rotation(a, b, c, "rr\n");
	else if (!(c->is_above_med) && !((c->target_node)->is_above_med))
		stacks_rotation(a, b, c, "rrr\n");
	finish_rotation(b, c, "b");
	finish_rotation(a, c->target_node, "a");
	push(b, a, "pa\n");
}

void	sort_all(t_node **a, t_node **b, int size)
{
	t_node	*smallest;

	while (size > 3)
	{
		push(a, b, "pb\n");
		size--;
	}
	sort_three(a, size);
	while (*b)
	{
		update_stacks(a, b);
		move_nodes(a, b);
	}
	set_position(a);
	smallest = get_smallest_node(a);
	if (smallest->is_above_med)
		while (*a != smallest)
			rotate(a, "ra\n");
	else
		while (*a != smallest)
			reverse_rotate(a, "rra\n");
}

void	push_swap(t_node **a, t_node **b)
{
	int	size_a;

	size_a = get_node_cnt(a);
	if (is_sorted(a))
		return ;
	if (size_a <= 3)
		sort_three(a, size_a);
	else if (size_a <= 5)
		sort_five(a, b, size_a);
	else
		sort_all(a, b, size_a);
}
