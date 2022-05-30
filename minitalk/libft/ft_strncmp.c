/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidan <mirhatfidann@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:21:51 by mfidan            #+#    #+#             */
/*   Updated: 2022/02/06 16:47:07 by mfidan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	a1;
	unsigned char	a2;

	while (n-- > 0)
	{
		a1 = *(unsigned char *)s1++;
		a2 = *(unsigned char *)s2++;
		if (a1 != a2)
			return (a1 - a2);
		if (a1 == '\0')
			return (0);
	}
	return (0);
}
