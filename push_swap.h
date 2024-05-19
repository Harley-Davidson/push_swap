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
	int				position;
	int				price;
	bool			is_cheapest;
	bool			is_above_med;
	struct s_node	*prev;
	struct s_node	*next;
	struct s_node	*target_node;
}	t_node;

// stack_utils
void 	add_node(t_node **stack, int arg);
void	init_stack(t_node **a, char **argv, int	argc);
void	free_stacks(t_node **a, t_node **b);
void	print_stack(t_node **node, char *stack_name);
void	set_position(t_node **b);
void	update_stacks(t_node **a, t_node **b);
int		get_node_cnt(t_node **a);
//t_node *get_first_node(t_node *node);
t_node	*get_last_node(t_node *node);
t_node	*get_cheapest_node(t_node **stack);
t_node	*get_smallest_node(t_node **stack);

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
void	update_stacks(t_node **a, t_node **b);
void	set_position(t_node **b);
void	sort_three(t_node **a, int size);
void	sort_five(t_node **a, t_node **b, int size);
void	sort_all(t_node **a, t_node **b, int size);
void	push_swap(t_node **a, t_node **b);

// other utils
long	ft_atoi_long(const char *nptr);
char	**offset_argv(int argc, char **argv);
int		is_duplicated(char **argv);
int		is_arg_error(char **argv);

#endif
