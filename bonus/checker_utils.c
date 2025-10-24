/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                    +#+#+#+#+#+   +#+       */
/*   Created: 2025/10/24 18:00:00 by bpichyal         #+#    #+#             */
/*   Updated: 2025/10/24 18:00:00 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	silent_rra(t_stack *a)
{
	int	tmp;
	int	i;

	if (a->size < 2)
		return ;
	tmp = a->arr[a->size - 1];
	i = a->size;
	while (--i > 0)
		a->arr[i] = a->arr[i - 1];
	a->arr[0] = tmp;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	char	*out;

	if (!s1 && !s2)
		return (NULL);
	l1 = (s1) ? ft_strlen(s1) : 0;
	l2 = (s2) ? ft_strlen(s2) : 0;
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
	size_t l = 0;
	while (s[l])
		l++;
	return (l);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
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