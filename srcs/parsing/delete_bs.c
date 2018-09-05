/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   delete_bs.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/05 11:29:57 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/09/05 11:53:36 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int		return_i(char *str, int i)
{
	if (str[i] == '\'')
	{
		while (str[i] || str[i] != '\'')
			i++;
	}
	else if (str[i] == '\"')
	{
		while (str[i] || str[i] != '\"')
			i++;
	}
	return (i);
}

static char		*clear_bs(char *str)
{
	char	*new;
	int		i;

	new = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			i = return_i(str, i);
		else if (str[i] == '\\')
		{
			
		}
		i++;
	}
	return (new);
}

int				delete_bs(char **line)
{
	char	*tmp;

	tmp = NULL;
	if (!(*line))
		return (1);
	if (ft_strstr(*line, "\\") == NULL)
		return (0);
	tmp = clear_bs(*line);
	if (tmp == NULL)
		return (0);
	ft_strdel(line);
	if (!(*line = ft_strdup(tmp)))
	{
		ft_strdel(&tmp);
		return (1);
	}
	ft_strdel(&tmp);
	return (0);
}
