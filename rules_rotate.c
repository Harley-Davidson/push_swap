/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:46:21 by mvoloshy          #+#    #+#             */
/*   Updated: 2024/05/04 20:46:26 by mvoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// implementation of ra:  Shift up all elements of stack a by 1.
//  The first element becomes the last one.
void	rotate(t_node **a, char* rule_name)
{
	t_node *first;
	t_node *second;
	t_node *last;

	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	second = first->next;
	second->prev = NULL;
	first->next = NULL;
	if (second->next == NULL)
	{
		first->prev = second;
		second->next = first;
	}
	else
	{
		last = get_last_node(second);
		first->prev = last;
		last->next = first;
	}
	*a = second;
	ft_putstr_fd(rule_name, 1);
}

void	rotate_both(t_node **a, t_node **b, char* rule_name)
{
	rotate(a, "");
	rotate(b, "");
	ft_putstr_fd(rule_name, 1);
}

// implementation of ra:   Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	reverse_rotate(t_node **a, char* rule_name)
{
	t_node *first;
	t_node *before_last;
	t_node *last;

	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	last = get_last_node(first);
	before_last = last->prev;
	if (first == before_last)
		first->next = NULL;
	else
		before_last->next = NULL;
	last->next = first;
	first->prev = last;
	last->prev = NULL;
	*a = last;
	ft_putstr_fd(rule_name, 1);
}

void	reverse_rotate_both(t_node **a, t_node **b, char* rule_name)
{
	reverse_rotate(a, "");
	reverse_rotate(b, "");
	ft_putstr_fd(rule_name, 1);
}
