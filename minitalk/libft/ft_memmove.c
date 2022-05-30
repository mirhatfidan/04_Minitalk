/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidan <mirhatfidann@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:13:40 by mfidan            #+#    #+#             */
/*   Updated: 2022/02/06 17:11:26 by mfidan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (0);
	if (dest > src)
	{
		d = dest + n;
		s = src + n;
		while (n-- > 0)
		{
			*--d = *--s;
		}
	}
	else
	{
		d = dest;
		s = src;
		while (n-- > 0)
		{
			*d++ = *s++;
		}
	}
	return (dest);
}
