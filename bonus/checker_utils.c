/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:59:36 by bpichyal          #+#    #+#             */
/*   Updated: 2025/10/28 15:11:30 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra_silent(t_stack *a)
{
	int	tmp;
	int	i;

	if (!a || a->size < 2)
		return ;
	tmp = a->arr[a->size - 1];
	i = a->size - 1;
	while (i > 0)
	{
		a->arr[i] = a->arr[i - 1];
		i--;
	}
	a->arr[0] = tmp;
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	l1;
	size_t	l2;
	char	*out;

	l1 = 0;
	l2 = 0;
	if (s1)
		l1 = ft_strlen(s1);
	if (s2)
		l2 = ft_strlen(s2);
	out = malloc(l1 + l2 + 1);
	if (!out)
		exit_error();
	if (s1)
		ft_memcpy(out, s1, l1);
	if (s2)
		ft_memcpy(out + l1, s2, l2);
	out[l1 + l2] = '\0';
	return (out);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dst);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
