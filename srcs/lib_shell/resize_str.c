/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   resize_str.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/08 09:48:23 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/11 15:30:46 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

int			resize_str(char **str, int len)
{
	char		*tmp;

	tmp = NULL;
	if (*str == NULL)
		return (1);
	if (len >= ft_strlen(*str))
	{
		ft_strdel(str);
		return (0);
	}
	tmp = ft_strsub(*str, len, (ft_strlen(*str) - len));
	if (tmp == NULL)
		return (1);
	ft_strdel(str);
	*str = ft_strdup(tmp);
	if (*str == NULL || ft_strlen(*str) == 0)
	{
		ft_strdel(str);
		ft_strdel(&tmp);
		return (1);
	}
	ft_strdel(&tmp);
	return (0);
}
