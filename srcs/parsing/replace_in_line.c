/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   replace_in_line.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/22 11:40:00 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/25 16:27:00 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
**  remplace ~ et $ dans line
**	Appeler dans check_validity
*/

static int		return_compt(char *str, int j)
{
	int		compt;

	compt = 0;
	if (str == NULL)
		return (0);
	if (str[j] == '?' || str[j] == '$')
		return (1);
	while (str[j] > 64 && str[j] < 91)
	{
		j++;
		compt++;
	}
	return (compt);
}

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
	j++;
	compt = return_compt(str, j);
	tmp = ft_strsub(str, i, compt + 1);
	j = ft_strlen(tmp) - 1;
	dol = ft_return_dollar(data, tmp, compt + 1);
	ret = insert_in_line(str, i, dol);
	ft_strdel(&dol);
	dol = ft_strsub(ret, 0, ft_strlen(ret) - j);
	ft_strdel(&ret);
	ft_strdel(&tmp);
	return (dol);
}

static char		*replace_suite(t_struct *data, char **str)
{
	int		i;
	int		bol;
	char	*line;

	i = 0;
	bol = 0;
	line = NULL;
	if (!(line = ft_strdup(*str)))
		return (NULL);
	while (line[i])
	{
		i = echap_quote(line, i, 1);
		if (line[i] == '\0')
			return (line);
		if (line[i] == '~' || line[i] == '$')
		{
			bol = line[i] == '~' ? 1 : 0;
			ft_strdel(&line);
			line = bol == 1 ? insert_in_line(*str, i, data->home) :
	return_dol(data, *str, i);
			return (line);
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
	if (ft_strstr(*line, "~") == NULL && ft_strstr(*line, "$") == NULL)
		return (0);
	tmp = replace_suite(data, line);
	if (tmp != NULL)
	{
		ft_strdel(line);
		*line = ft_strdup(tmp);
	}
	ft_strdel(&tmp);
	delete_back_slash(line);
	return (0);
}
