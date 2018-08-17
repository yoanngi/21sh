/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_line_vide.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/26 12:06:01 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/17 15:55:08 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int	suite_vide(char *str, int i)
{
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != ';')
			return (1);
		i++;
	}
	return (0);
}

int			ft_check_line_vide(char *str, t_struct **data)
{
	int		i;

	i = 0;
	if (ft_strlen(str) == 0)
		return (0);
	if (ft_strlen(str) == 1 && str[0] == ';')
	{
		(*data)->code_erreur = 258;
		ft_putstr_fd("21sh: syntax error near unexpected token `;'\n", 2);
		return (0);
	}
	if (ft_strstr(str, "\"") == NULL && ft_strstr(str, "\'") == NULL)
	{
		if (ft_strstr(str, ";;") != NULL)
		{
			(*data)->code_erreur = 258;
			ft_putstr_fd("21sh: syntax error near unexpected token `;;'\n", 2);
			return (0);
		}
	}
	return (suite_vide(str, i));
}
