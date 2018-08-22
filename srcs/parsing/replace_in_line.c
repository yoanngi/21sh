/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   replace_in_line.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/22 11:40:00 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/22 15:46:05 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
**  remplace ~, - et $ dans line
*/

static int		check_regex_classic(t_struct *data, char **line)
{
	if (ft_strcmp(*line, "$$") == 0)
	{
		ft_strdel(line);
		*line = ft_itoa_base(data->pid, 10);
		return (0);
	}
	if (ft_strcmp(*line, "$?") == 0)
	{
		ft_strdel(line);
		*line = ft_itoa_base(data->code_erreur, 10);
		return (0);
	}
	if (ft_strcmp(*line, "~") == 0 || ft_strcmp(*line, "~-") == 0 ||
	ft_strcmp(*line, "~+") == 0)
	{
		ft_strdel(line);
		*line = ft_return_home(data);
		return (0);
	}
	if (ft_strcmp(*line, "-") == 0)
	{
		ft_strdel(line);
		*line = ft_return_moins(data);
		return (0);
	}
	return (1);
}

static int		insert_str_suite(char **str, char *tmp, int i)
{
	char	*new;
	char	*tmp2;
	int		len;

	new = NULL;
	tmp2 = NULL;
	if (!str || !tmp)
		return (1);
	len = ft_strlen(tmp);
	if (i == 0)
	{
		new = ft_strdup(*str);
		ft_strdel(str);
		*str = ft_strjoin(tmp, new + ft_strlen(tmp));
		ft_strdel(&new);
	}
	return (1);
}

static int		insert_in_str(t_struct *data, char **str, int i)
{
	char	*tmp;
	char	*new;
	int		len;
	int		ret;

	tmp = NULL;
	new = NULL;
	len = 0;
	ret = 0;
	if (!data || !str)
		return (1);
	if (!(new = ft_strsub(*str, i, ft_strlen(*str) - i)))
		return (1);
	if (new[0] == '~')
		tmp = ft_return_home(data);
	else if (new[0] == '$')
	{
		len++;
		while (new[len] >= 65 && new[len] <= 90 )
			len++;
		printf("LEN = %d\n", len);
		if (len > 1)
			tmp = ft_return_dollar(data, new, len);
		printf("tmp = %s\n", tmp);
	}
	insert_str_suite(str, tmp, i);
	ft_strdel(&new);
	if (tmp == NULL)
	{
		ft_strdel(str);
		return (0);
	}
	ret = ft_strlen(tmp);
	ft_strdel(&tmp);
	return (ret - 1);
}

static int		replace_line(char **line, char *str)
{
	ft_strdel(line);
	if (!(*line = ft_strdup(str)))
		return (1);
	return (0);
}

static int		replace_in_line_deux(t_struct *data, char **str, int i)
{
	char	*tmp;

	if (!(tmp = ft_strdup(*str)))
		return (1);
	while (tmp[i])
	{
		if (tmp[i] == '\'')
		{
			i++;
			while (tmp[i] != '\'')
				i++;
		}
		else if (tmp[i] == '\"')
		{
			i++;
			while (tmp[i] != '\"')
				i++;
		}
		else if (tmp[i] == '~' || tmp[i] == '$')
			i = insert_in_str(data, str, i);
		i++;
	}
	ft_strdel(&tmp);
	return (0);
}

int				replace_in_line(t_struct *data, char **line)
{
	char	*tmp;
	int		i;

	tmp = NULL;
	i = 0;
	printf("line = %s\n", *line);
	if (line == NULL || ft_strlen(*line) < 1)
		return (1);
	if ((ft_strstr(*line, "~") == NULL && ft_strstr(*line, "-") == NULL &&
	ft_strstr(*line, "$") == NULL))
		return (0);
	if (check_regex_classic(data, line) == 0)
		return (0);
	if (!(tmp = ft_strdup(*line)))
		return (0);
	replace_in_line_deux(data, &tmp, i);
	if (replace_line(line, tmp) == 1)
		return (0);
	ft_strdel(&tmp);
	printf("end (%s)\n", __func__);
	return (0);
}
