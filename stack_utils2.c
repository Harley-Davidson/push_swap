#include "push_swap.h"

static void	set_target_node(t_node **a, t_node **b)
{
	t_node	*x;
	t_node	*y;
	t_node	*t;
	int		i;

	y = *b;
	while (y)
	{
		i = INT_MAX;
		x = *a;
		while (x)
		{
			if(x->value > y->value && x->value < i)
			{
				i = x->value;
				t = x;
			}
			x = x->next;
		}
		if (i == INT_MAX)
			y->target_node = get_smallest_node(a);
		else
			y->target_node = t;
		y = y->next;
	}
}

static void	set_price(t_node **a, t_node **b)
{
	int		size_a;
	int		size_b;
	t_node	*y;

	size_a = get_node_cnt(a);
	size_b = get_node_cnt(b);
	y = *b;
	while (y)
	{
		y->price = y->position;
		if(!(y->is_above_med))
			y->price = size_b - y->position;
		if ((y->target_node)->is_above_med)
			y->price += (y->target_node)->position;
		else
			y->price += size_a - (y->target_node)->position;
		y = y->next;
	}
}

static void	set_cheapest(t_node **b)
{
	int		best_price;
	t_node	*best_node;
	t_node	*y;

	if (!b || !*b)
		return ;
	y = *b;
	best_node = NULL;
	best_price = INT_MAX;
	while (y)
	{
		if(y->price < best_price)
		{
			best_price = y->price;
			best_node = y;
		}
		y = y->next;
	}
	if (best_node)
		best_node->is_cheapest = true;
}

void	set_position(t_node **b)
{
	int		i;
	int		med;
	t_node	*y;

	if (b == NULL)
		return ;
	med = get_node_cnt(b) / 2;
	i = 0;
	y = *b;
	while (y)
	{
		y->position = i;
		y->is_above_med = (i <= med);
		y = y->next;
		i++;
	}
}

void	update_stacks(t_node **a, t_node **b)
{
	set_position(a);
	set_position(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}