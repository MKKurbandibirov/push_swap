/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 13:01:29 by nfarfetc          #+#    #+#             */
/*   Updated: 2021/12/27 14:55:54 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line/get_next_line.h"

#include <stdio.h>

int	str_cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char		**nums;
	int			count;
	t_stacks	stacks;

	nums = valid_helper(argc, argv);
	count = 0;
	while (nums[count])
		count++;
	init_stacks(&stacks);
	stacks.stk_a = validator(count, nums);
	
	
	char	*str;
	int		ok;

	ok = 1;
	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		if (str_cmp(str, "sa"))
			swap(&(stacks.stk_a));
		else if (str_cmp(str, "sb"))
			swap(&(stacks.stk_b));
		else if (str_cmp(str, "ss"))
		{
			swap(&(stacks.stk_a));
			swap(&(stacks.stk_b));
		}
		else if (str_cmp(str, "ra"))
			rotate(&(stacks.stk_a));
		else if (str_cmp(str, "rb"))
			rotate(&(stacks.stk_b));
		else if (str_cmp(str, "rr"))
		{
			rotate(&(stacks.stk_a));
			rotate(&(stacks.stk_b));
		}
		else if (str_cmp(str, "rra"))
			reverse_rotate(&(stacks.stk_a));
		else if (str_cmp(str, "rrb"))
			reverse_rotate(&(stacks.stk_b));
		else if (str_cmp(str, "rrr"))
		{
			reverse_rotate(&(stacks.stk_a));
			reverse_rotate(&(stacks.stk_b));
		}
		else if (str_cmp(str, "pa"))
			push(&(stacks.stk_a), &(stacks.stk_b));
		else if (str_cmp(str, "pb"))
			push(&(stacks.stk_b), &(stacks.stk_a));
		else if (str_cmp(str, "pp"))
		{
			push(&(stacks.stk_a), &(stacks.stk_b));
			push(&(stacks.stk_b), &(stacks.stk_a));
		}
		else
		{
			write (2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
	}
	
	while (stacks.stk_a)
	{
		printf("|%3d|\n", stacks.stk_a->val);
		stacks.stk_a = stacks.stk_a->next;
	}
	return (0);
}
