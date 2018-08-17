/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   split_echo.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/17 14:38:34 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/17 16:51:53 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

static char		*check_str(char *tabi, char *str, int j)
{
	char	*new;

	new = NULL;
	while (str[j])
	{
		if (str[j] == tabi[j])
			j++;
		else if (str[j] == ' ')
			j++;
		else if (str[i] == '\"')
			// pa fini
	}
	return (new);
}

static char		**complete_split(char **tabl, char *str)
{
	char	**new;
	int		i;
	int		j;

	new = NULL;
	i = 0;
	j = 0;
	new = (char **)malloc(sizeof(char *) * (ft_len_tab(tabl) + 1));
	while (tabl[i])
	{
		new[i]= check_str(tabl[i], str, j);
		j += ft_strlen(new[i]);
		i++;
	}
	return (new);
}

char			**split_echo(char *str)
{
	int		i;
	char	**new;
	char	**tmp;

	i = 0;
	new = NULL;
	tmp = NULL;
	if (ft_strstr(str, "\"") == NULL || ft_strstr(str, "\'") == NULL)
		new = ft_strsplit(str, ' ');
	else
	{

		tmp = ft_strsplit(str, ' ');
		new = complete_split(tmp, str);
		tmp = ft_del_tab(tmp);
	}
	return (new);
}
