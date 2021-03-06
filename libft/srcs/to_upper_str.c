/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   to_upper_str.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/14 14:19:39 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/14 14:30:11 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*to_upper_str(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_islower(s[i]))
			s[i] -= 32;
		i++;
	}
	return (s);
}
