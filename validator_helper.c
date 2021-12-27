/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 12:36:13 by nfarfetc          #+#    #+#             */
/*   Updated: 2021/12/27 13:52:43 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_stacks *st)
{
	st->stk_a = NULL;
	st->stk_b = NULL;
	st->cur = NULL;
	st->min_op = 0;
	st->method_v = 0;
	st->len_a = 0;
	st->len_b = 0;
}

static int	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		i++;
	}
	return (i);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	if (!(s1 && s2))
		return (NULL);
	new = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!new)
	{
		free(s1);
		exit (EXIT_FAILURE);
	}
	i = 0;
	j = 0;
	while (s1[i])
		new[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new[j++] = s2[i++];
	new[j] = '\0';
	free(s1);
	return (new);
}

char	**valid_helper(int argc, char **argv)
{
	char	**numbers;
	char	*tmp;
	int		i;

	i = 1;
	tmp = (char *)malloc(sizeof(char));
	if (!tmp)
		exit (EXIT_FAILURE);
	tmp[0] = '\0';
	while (i < argc)
	{
		tmp = ft_strjoin(tmp, " ");
		if (!argv[i][0])
		{
			free (tmp);
			write(2, "Error\n", 6);
			exit (EXIT_FAILURE);
		}
		tmp = ft_strjoin(tmp, argv[i]);
		i++;
	}
	numbers = ft_split(tmp, ' ');
	free(tmp);
	return (numbers);
}
