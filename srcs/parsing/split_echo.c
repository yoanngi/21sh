/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   split_echo.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/17 14:38:34 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/17 15:18:04 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

char		**split_echo(char *str)
{
	int		i;
	char	**new;

	i = 0;
	new = NULL;
	if (ft_strstr(str, "\"") == NULL || ft_strstr(str, "\'") == NULL)
		new = ft_strsplit(str, ' ');
	else
	{
		new = ft_strsplit(str, ' ');
		// a modif
	}
	return (new);
}
