/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomed <magomed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 13:01:29 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/01/31 19:15:43 by magomed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "GNL/get_next_line.h"

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

int	norm_helper_1(t_stacks *stacks, char *str)
{
	if (str_cmp(str, "sa\n"))
		swap(&(stacks->stk_a));
	else if (str_cmp(str, "sb\n"))
		swap(&(stacks->stk_b));
	else if (str_cmp(str, "ss\n"))
	{
		swap(&(stacks->stk_a));
		swap(&(stacks->stk_b));
	}
	else if (str_cmp(str, "ra\n"))
		rotate(&(stacks->stk_a));
	else if (str_cmp(str, "rb\n"))
		rotate(&(stacks->stk_b));
	else if (str_cmp(str, "rr\n"))
	{
		rotate(&(stacks->stk_a));
		rotate(&(stacks->stk_b));
	}
	else
		return (1);
	return (0);
}

int	norm_helper_2(t_stacks *stacks, char *str)
{
	if (str_cmp(str, "rra\n"))
		reverse_rotate(&(stacks->stk_a));
	else if (str_cmp(str, "rrb\n"))
		reverse_rotate(&(stacks->stk_b));
	else if (str_cmp(str, "rrr\n"))
	{
		reverse_rotate(&(stacks->stk_a));
		reverse_rotate(&(stacks->stk_b));
	}
	else if (str_cmp(str, "pa\n"))
		push(&(stacks->stk_a), &(stacks->stk_b));
	else if (str_cmp(str, "pb\n"))
		push(&(stacks->stk_b), &(stacks->stk_a));
	else if (str_cmp(str, "pp\n"))
	{
		push(&(stacks->stk_a), &(stacks->stk_b));
		push(&(stacks->stk_b), &(stacks->stk_a));
	}
	else
		return (1);
	return (0);
}

void	check_str(t_stacks *stacks)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		else if (norm_helper_1(stacks, str) + norm_helper_2(stacks, str) == 2)
		{
			write (1, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		free(str);
	}
	if (is_sorted(stacks->stk_a))
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
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
	check_str(&stacks);
	stack_free(stacks.stk_a);
	stack_free(stacks.stk_b);
	return (0);
}
