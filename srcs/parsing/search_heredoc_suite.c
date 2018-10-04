/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   search_heredoc.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/28 11:34:39 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/30 10:03:01 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
**	cat << test auteur
**	on va jusqu'a test et si il reste des arguments
**	on les passes en parametre de la fonction
*/

int			start_heredoc_opt(char *str, int i)
{
	int		len;

	len = ft_strlen(str);
	while (str[i] && (str[i] != '<' && str[i + 1] != '<'))
		i++;
	i += 1;
	if (str[i] == '<' && str[i + 1] == '<')
	{
		i += 2;
		if (str[i] == ' ' || str[i] == '\t')
		{
			while (str[i] && (str[i] == ' ' || str[i] == '\t'))
				i++;
			i += 1;
		}
		while (str[i])
		{
			if (str[i] == ' ' || str[i] == '\t')
				return (i);
			i++;
		}
	}
	return (ft_strlen(str));
}

int			end_heredoc_opt(char *str, int i)
{
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '|' || str[i] == '>')
			return (i);
		i++;
	}
	return (i);
}
