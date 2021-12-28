/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:41:20 by nfarfetc          #+#    #+#             */
/*   Updated: 2021/12/28 12:42:49 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

static long long	helper(char *str, int *sign)
{
	int			i;
	long long	res;

	i = -1;
	res = 0;
	*sign = 1;
	while (str[++i] != '\0')
	{
		if (str[i] == '-')
		{
			*sign = -1;
			i++;
		}
		if (!ft_isdigit(str[i]))
		{
			write(2, "Error\n", 6);
			return (ERR_CODE);
		}
		res = res * 10 + (str[i] - '0');
	}
	return (res);
}

static t_list	*processor(int count, char **nums, t_list *stk_a)
{
	int			sign;
	int			i;
	long long	res;

	res = 0;
	i = 0;
	while (i < count)
	{
		res = helper(nums[i], &sign);
		if (res == ERR_CODE)
			return (NULL);
		res = sign * res;
		if (res > 2147483647 || res < -2147483648)
		{
			write(2, "Error\n", 6);
			return (NULL);
		}
		stk_a = stk_push_back(stk_a, (int)res);
		if (!stk_a)
			return (NULL);
		i++;
	}
	return (stk_a);
}

static void	*check_dublicate(t_list *stk_a)
{
	t_list		*i_stk;
	t_list		*j_stk;

	i_stk = stk_a;
	while (i_stk)
	{
		j_stk = i_stk->next;
		while (j_stk)
		{
			if (i_stk->val == j_stk->val)
			{
				write(2, "Error\n", 6);
				stack_free(stk_a);
				exit(EXIT_FAILURE);
			}
			j_stk = j_stk->next;
		}
		i_stk = i_stk->next;
	}
	return (stk_a);
}

t_list	*validator(int count, char **nums)
{
	t_list	*stk_a;
	int		i;

	stk_a = NULL;
	stk_a = processor(count, nums, stk_a);
	i = 0;
	while (nums[i])
	{
		free(nums[i]);
		i++;
	}
	free(nums);
	nums = NULL;
	if (!stk_a)
	{
		stack_free(stk_a);
		exit(EXIT_FAILURE);
	}
	return (check_dublicate(stk_a));
}
