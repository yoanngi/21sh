/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_line_vide.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/26 12:06:01 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/11 11:41:29 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

int			ft_check_line_vide(char *str, t_struct **data)
{
	int		i;

	i = 0;
	(*data)->code_erreur = 0;
	if (ft_strlen(str) == 0)
		return (0);
	if (ft_strstr(str, "\"") == NULL && ft_strstr(str, "\'") == NULL)
	{
		if (ft_strstr(str, ";;") != NULL)
		{
			(*data)->code_erreur = 258;
			ft_putstr_fd("21sh: syntax error near unexpected token `;;'\n", 2);
			return (0);
		}
	}
	while (str[i])
	{
		if (str[i] != ' ' || str[i] != ';')
			return (1);
		i++;
	}
	return (0);
}
