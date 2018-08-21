/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   split_echo_suite.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/21 10:49:44 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/21 11:11:59 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

int		resize_str_echo(char **str, int start, int len)
{
	char	*tmp;

	tmp = NULL;
	if (!(tmp = ft_strdup(*str)))
		return (1);
	ft_strdel(str);
	*str = ft_strsub(tmp, start, len);
	ft_strdel(&tmp);
	return (0);
}
