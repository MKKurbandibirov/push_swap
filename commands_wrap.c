/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_wrap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 15:01:08 by nfarfetc          #+#    #+#             */
/*   Updated: 2021/12/25 15:54:36 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_and_write(t_stacks *stacks, int c)
{
	if (c == 'a')
	{
		rotate(&(stacks->stk_a));
		write (1, "ra\n", 3);
	}
	else if (c == 'b')
	{
		rotate(&(stacks->stk_b));
		write (1, "rb\n", 3);
	}
	else if (c == 'r')
	{
		rotate(&(stacks->stk_a));
		rotate(&(stacks->stk_b));
		write (1, "rr\n", 3);
	}
}

void	rev_rotate_and_write(t_stacks *stacks, int c)
{
	if (c == 'a')
	{
		reverse_rotate(&(stacks->stk_a));
		write (1, "rra\n", 4);
	}
	else if (c == 'b')
	{
		reverse_rotate(&(stacks->stk_b));
		write (1, "rrb\n", 4);
	}
	else if (c == 'r')
	{
		reverse_rotate(&(stacks->stk_a));
		reverse_rotate(&(stacks->stk_b));
		write (1, "rrr\n", 4);
	}
}

void	push_and_write(t_stacks *stacks, int c)
{
	if (c == 'b')
	{
		push(&(stacks->stk_b), &(stacks->stk_a));
		write (1, "pb\n", 3);
		stacks->len_a--;
		stacks->len_b++;
	}
	else if (c == 'a')
	{
		push(&(stacks->stk_a), &(stacks->stk_b));
		write (1, "pa\n", 3);
		stacks->len_a++;
		stacks->len_b--;
	}
}
