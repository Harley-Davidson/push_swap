/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:54:16 by mvoloshy          #+#    #+#             */
/*   Updated: 2024/04/30 14:54:19 by mvoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./libft/libft.h"
#include "./libft/ft_printf.h"

typedef struct s_node
{
	int				value;
	int				stack_position;
	int				price;
	bool			is_lowest_price;
	bool			is_above_med;
	struct s_node	*prev;
	struct s_node	*next;
	struct s_node	*target_node;
}	t_node;

// stack_utils
void	print_stack(t_node **node);
t_node *get_last_node(t_node *node);
void 	add_node(t_node **stack, int arg);
void	init_stack(t_node **a, char **argv, int	argc);
int		get_node_cnt(t_node **a);
int		is_sorted(t_node **a);
void	free_stacks(t_node **a, t_node **b);

// rules: rules_swap_push & rules_rotate
void	swap(t_node **a, char* rule_name);
void	swap_both(t_node **a, t_node **b, char* rule_name);
void	push(t_node **a, t_node **b, char* rule_name);
void	rotate(t_node **a, char* rule_name);
void	rotate_both(t_node **a, t_node **b, char* rule_name);
void	reverse_rotate(t_node **a, char* rule_name);
void	reverse_rotate_both(t_node **a, t_node **b, char* rule_name);

// sorting
int		is_sorted(t_node **a);
void	quick_sort(t_node **a, t_node **b);
void	sort_three(t_node **a);
void	sort_five(t_node **a, t_node **b);
void	push_swap(t_node **a, t_node **b);

// other utils
long	ft_atoi_long(const char *nptr);

#endif
