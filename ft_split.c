/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modoukal <modoukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 11:52:51 by modoukal          #+#    #+#             */
/*   Updated: 2022/06/30 13:39:39 by modoukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static int	ft_cw(const char *s1, char to_find)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s1[i] == to_find)
		i++;
	while (s1[i])
	{
		if (s1[i] == to_find && s1[i + 1] == to_find)
			exit(write(1, "Error\n", 6));
		if (s1[i] == to_find && s1[i + 1] != to_find && s1[i + 1] != '\0')
			count ++;
		i++;
	}
	return (count + 1);
}

static void	ft_khwi(int j, char **p)
{
	int	d;

	d = 0;
	while (j >= 0)
	{
		free(p[d]);
		d++;
		j--;
	}
	free(p);
	return ;
}

static void	alloc(const char *s1, char to_find, char **p, int i)
{
	int	j;
	int	k;
	int	end;

	i = 0;
	j = -1;
	while (s1[i])
	{
		if (s1[i] != to_find && s1[i])
		{
			end = i;
			while (s1[end] != to_find && s1[end])
				end++;
			p[++j] = (char *)calloc(sizeof(char) * (end - i) + 1, 1);
			if (!p[j])
				return (ft_khwi(j, p));
			k = 0;
			while (i < end)
				p[j][k++] = s1[i++];
		}
		if (s1[i])
			i++;
	}
}

char	**ft_split(const char *s1, char c)
{
	char	**p;
	int		o;

	o = 0;
	if (!s1)
		return (0);
	p = (char **)calloc(sizeof(char *) * (ft_cw(s1, c) + 1), 1);
	if (!p)
		return (0);
	alloc(s1, c, p, o);
	return (p);
}