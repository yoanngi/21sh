/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   replace_in_line.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/22 11:40:00 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/09/05 16:11:52 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
**  remplace ~ et $ dans line
**	Appeler dans check_validity
*/

static char		*return_dol(t_struct *data, char *str, int i)
{
	char	*dol;
	char	*tmp;
	char	*ret;
	int		j;
	int		compt;

	dol = NULL;
	tmp = NULL;
	ret = NULL;
	j = i;
	compt = 0;
	while (str[j] > 64 && str[j] < 91)
		compt++;
	tmp = ft_strsub(str, i, compt + 1);
	dol = ft_return_dollar(data, tmp, compt + 1);
	ret = insert_in_line(str, i, dol);
	return (ret);
}

static char		*replace_suite(t_struct *data, char **str)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	if (!(line = ft_strdup(*str)))
		return (NULL);
	while (line[i])
	{
		i = echap_quote(line, i, 1);
		if (line[i] == '~')
		{
			ft_strdel(&line);
			line = insert_in_line(*str, i, data->home);
			i = 0;
		}
		if (line[i] == '$')
		{
			ft_strdel(&line);
			line = return_dol(data, *str, i);
			i = 0;
		}
		i++;
	}
	return (line);
}

int				replace_in_line(t_struct *data, char **line)
{
	char	*tmp;

	tmp = NULL;
	if (*line == NULL)
		return (1);
	if (ft_strlen(*line) < 1)
		return (1);
	if (ft_strstr(*line, "~") == NULL || ft_strstr(*line, "$") == NULL)
		return (0);
	if (!(tmp = ft_strdup(*line)))
		return (1);
	tmp = replace_suite(data, line);
	if (tmp != NULL)
	{
		ft_strdel(line);
		*line = ft_strdup(tmp);
	}
	ft_strdel(&tmp);
	return (0);
}
