/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:05:37 by nfarfetc          #+#    #+#             */
/*   Updated: 2021/12/17 11:40:27 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stk_size(t_stack *stk_a)
{
	t_stack	*current;
	int		size;

	current = stk_a;
	size = 0;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

void	bubble_sort(int *a, int n)
{
	int	i;
	int	j;
	int	tmp;

	i = n - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (a[j] > a[j + 1])
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
			j++;
		}
		i--;
	}
}

int	*get_indexes(t_stack *stk_a)
{
	int		*arr_a;
	int		i;
	int		len;
	t_stack	*current;

	current = stk_a;
	len = stk_size(current);
	arr_a = (int *)malloc(sizeof(int) * len);
	if (!arr_a)
		return (NULL);
	i = 0;
	while (current)
	{
		arr_a[i] = current->content;
		i++;
		current = current->next;
	}
	bubble_sort(arr_a, len);
	return (arr_a);
}

t_stack	*indexation(t_stack *stk_a)
{
	int		*arr_a;
	int		i;
	int		len;
	t_stack	*current;

	current = stk_a;
	arr_a = get_indexes(stk_a);
	if (!arr_a)
		return (NULL);
	len = stk_size(stk_a);
	while (current)
	{
		i = 0;
		while (i < len)
		{
			if (current->content == arr_a[i])
				current->index = i;
			i++;
		}
		current = current->next;
	}
	free(arr_a);
	arr_a = NULL;
	return (stk_a);
}
