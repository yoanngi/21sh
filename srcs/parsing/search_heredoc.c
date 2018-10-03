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

static int	ft_return_heredoc(char *str, char **tmp, int i, int opt)
{
	int		j;
	int		len;

	j = i;
	len = ft_strlen(str) - 1;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if (opt == 1 && (i == len || (str[i] == ' ' || str[i] == '|' ||
	str[i] == '>' || str[i] == '<')))
		{
			*tmp = ft_strsub(str, j, i - j + 1);
			return (i);
		}
		if (opt == 2 && (i == len || (str[i] == '>' && str[i + 1] == '>')))
		{
			*tmp = ft_strsub(str, j, i - j + 1);
			return (i);
		}
		i++;
	}
	return (len + 1);
}

static char	**heredoc_simple(char *str, int i, int *j)
{
	char	*tmp;
	char	**new;

	tmp = NULL;
	new = NULL;
	*j = ft_return_heredoc(str, &tmp, i, 1);
	if (tmp == NULL)
		return (NULL);
	if (!(new = (char **)malloc(sizeof(char *) * 2)))
		return (NULL);
	new[0] = ft_strdup(tmp);
	new[1] = NULL;
	ft_strdel(&tmp);
	return (new);
}
/*
static int	clear_heredoc(char **str)
{
	char	*tmp;
	int		i;

	tmp = NULL;
	i = 0;
	if (!(*str))
		return (1);
	if (!(tmp = ft_strdup(*str)))
		return (1);
	while (i != ft_strlen(tmp))
	{
		if (tmp[i] == '<' && tmp[i + i] == '<')
		{
			printf("HEEEEEEEEEEEEEEEERE\n");
			ft_strdel(str);
			*str = ft_strsub(tmp, i + 1, ft_strlen(tmp) - (i + 1));
			ft_strdel(&tmp);
			return (0);
		}
		i++;
	}
	ft_strdel(&tmp);
	return (0);
}*/

int			search_heredoc(t_cmd **lst, char *str, int i, int j)
{
	char	*tmp;

	tmp = NULL;
	if (!lst || !str)
		return (-1);
	if ((*lst)->op_next == 4)
		(*lst)->heredoc = heredoc_simple(str, i, &j);
	else if ((*lst)->op_next == 5)
	{
		(*lst)->line = ft_strdup(str);
		(*lst)->heredoc_str = heredoc();
		printf("LAAAAAAAAAAAAAA-> %s\n", (*lst)->heredoc_str);
		//clear_heredoc(&(*lst)->heredoc_str);
	}
	change_prompt(&g_info, 0);
/*	if (g_info.h_d.fill)
		ft_strdel(&g_info.h_d.fill);*/
	ft_strdel(&(*lst)->line);
	ft_strdel(&tmp);
	return (j);
}