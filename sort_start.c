/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 11:25:51 by nfarfetc          #+#    #+#             */
/*   Updated: 2021/12/28 19:04:50 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble(int *arr, int n)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				t = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = t;
			}
			j++;
		}
		i++;
	}
}

static int	find_mid(t_stacks *stacks)
{
	int	i;
	int	mid;
	int	*arr;

	i = 0;
	arr = malloc(sizeof(int) * stacks->len_a);
	stacks->cur = stacks->stk_a;
	while (stacks->cur)
	{
		arr[i] = stacks->cur->val;
		i++;
		stacks->cur = stacks->cur->next;
	}
	bubble(arr, stacks->len_a);
	mid = arr[stacks->len_a / 2];
	free(arr);
	return (mid);
}

static int	find_min(t_stacks *stacks)
{
	int	min;

	min = 2147483647;
	stacks->cur = stacks->stk_a;
	while (stacks->cur)
	{
		if (stacks->cur->val < min)
			min = stacks->cur->val;
		stacks->cur = stacks->cur->next;
	}
	return (min);
}

static int	find_max(t_stacks *stacks)
{
	int		max;

	max = -1;
	stacks->cur = stacks->stk_a;
	while (stacks->cur)
	{
		if (stacks->cur->val > max)
			max = stacks->cur->val;
		stacks->cur = stacks->cur->next;
	}
	return (max);
}

void	start_push_b(t_stacks *stacks)
{
	int		max;
	int		min;
	int		mid;

	max = find_max(stacks);
	min = find_min(stacks);
	mid = find_mid(stacks);
	stacks->cur = stacks->stk_a;
	while (stacks->len_a > 3)
	{
		if (stacks->stk_a->val != min && stacks->stk_a->val != max
			&& stacks->stk_a->val != mid)
			push_and_write(stacks, 'b');
		else
			rotate_and_write(stacks, 'a');
	}
}
