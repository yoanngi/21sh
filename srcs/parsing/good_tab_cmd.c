/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   good_tab_cmd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/08 15:29:39 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/11 16:35:40 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
**  Search L'operateur (> ou >>)
*/

int				what_is_op(char *str, int i)
{
	int		ret;

	ret = 0;
	if (i + 1 > ft_strlen(str))
		return (0);
	if (str[i] == '>' && str[i + 1] == '>')
		ret = 3;
	else
		ret = 2;
	return (ret);
}

/*
**	insert la commande a executer et search les redirections a faire
*/

int				good_tab_cmd(t_struct *data, t_cmd **lst, char *str, int i)
{
	char		*tmp;
	int			ret;
	int			start;

	tmp = NULL;
	ret = 0;
	start = 0;
	if (str == NULL)
		return (0);
	if (i == ft_strlen(str) - 1)
		tmp = ft_strdup(str);
	else if (str[i] == '>' && ft_isdigit(str[i - 1] == 0))
		tmp = ft_strsub(str, start, i - 3);
    else
		tmp = ft_strsub(str, start, i - 2);
	insert_cmd_simple(data, lst, tmp);
	ret = ft_strlen(tmp);
	ft_strdel(&tmp);
	if ((*lst)->op_next == 2 || (*lst)->op_next == 3)
		ret = search_redirection(lst, str, i, i);
	return (ret);
}
