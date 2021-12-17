/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:41:20 by nfarfetc          #+#    #+#             */
/*   Updated: 2021/12/17 11:12:07 by nfarfetc         ###   ########.fr       */
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
			write(0, "Error\n", 6);
			return (ERR_CODE);
		}
		res = res * 10 + (str[i] - '0');
	}
	return (res);
}

static t_stack	*processor(int argc, char **argv, t_stack *stk_a)
{
	int			sign;
	long long	res;

	res = 0;
	while (argc > 1)
	{
		res = helper(argv[argc - 1], &sign);
		if (res == ERR_CODE)
			return (NULL);
		res = sign * res;
		if (res > 2147483647 || res < -2147483648)
		{
			write(0, "Error\n", 6);
			return (NULL);
		}
		stk_a = stk_push_back(stk_a, (int)res);
		if (!stk_a)
			return (NULL);
		argc--;
	}
	return (stk_a);
}

static void	*check_dublicate(t_stack *stk_a)
{
	t_stack		*i_stk;
	t_stack		*j_stk;

	i_stk = stk_a;
	while (i_stk)
	{
		j_stk = i_stk->next;
		while (j_stk)
		{
			if (i_stk->content == j_stk->content)
			{
				write(0, "Error\n", 6);
				stack_free(stk_a);
				return (NULL);
			}
			j_stk = j_stk->next;
		}
		i_stk = i_stk->next;
	}
	return (stk_a);
}

t_stack	*validate(int argc, char **argv)
{
	t_stack		*stk_a;

	if (argc < 2)
		return (NULL);
	stk_a = NULL;
	stk_a = processor(argc, argv, stk_a);
	if (!stk_a)
	{
		stack_free(stk_a);
		return (NULL);
	}
	return (check_dublicate(stk_a));
}
