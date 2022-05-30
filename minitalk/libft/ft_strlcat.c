/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidan <mirhatfidann@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:42:46 by mfidan            #+#    #+#             */
/*   Updated: 2022/02/22 14:48:08 by mfidan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (size < len_dst)
		return (len_src + size);
	else
	{
		dest = dest + len_dst;
		ft_strlcpy(dest, src, size - len_dst);
		return (len_src + len_dst);
	}
}
