/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/03 11:47:24 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/03 11:47:27 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*cast_dst;
	unsigned char	*cast_src;

	i = 0;
	cast_dst = (unsigned char*)dst;
	cast_src = (unsigned char*)src;
	if (src < dst)
	{
		while (len != 0)
		{
			cast_dst[len - 1] = cast_src[len - 1];
			len--;
		}
	}
	while (i < len)
	{
		cast_dst[i] = cast_src[i];
		i++;
	}
	dst = (void *)cast_dst;
	return (dst);
}
