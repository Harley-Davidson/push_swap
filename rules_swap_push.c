/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_swap_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:34:57 by mvoloshy          #+#    #+#             */
/*   Updated: 2024/05/04 16:35:14 by mvoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// implementation of sa: Swap the first 2 elements at the top of stack a.
//  Do nothing if there is only one or no elements.
void	swap(t_node **a, char *rule_name)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	second = first->next;
	third = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	if (third == NULL)
		first->next = NULL;
	else
	{
		first->next = third;
		third->prev = first;
	}
	*a = second;
	ft_putstr_fd(rule_name, 1);
}

void	swap_both(t_node **a, t_node **b, char *rule_name)
{
	swap(a, "");
	swap(b, "");
	ft_putstr_fd(rule_name, 1);
}

// implementation of pa: Take the first element at the top of b
//  and put it at the top of a. Do nothing if b is empty.
void	push(t_node **b, t_node **a, char *rule_name)
{
	t_node	*first_b;

	if (b == NULL || *b == NULL)
		return ;
	first_b = *b;
	*b = (*b)->next;
	if (*b != NULL)
		(*b)->prev = NULL;
	first_b->next = *a;
	if (*a != NULL)
		(*a)->prev = first_b;
	*a = first_b;
	ft_putstr_fd(rule_name, 1);
}
