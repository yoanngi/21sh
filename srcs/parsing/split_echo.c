/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   split_echo.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/17 14:38:34 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/09/05 15:16:55 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"


static void	debug(char ***tabl)
{
	int		i;

	i = 0;
	//return ;
	printf("***********************************\n");
	while ((*tabl)[i])
	{
		printf("tabl[%d] = %s\n", i, (*tabl)[i]);
		i++;
	}
	printf("***********************************\n\n");
}

static int	echap_word(char *str, int i)
{
	while (str[i] && (str[i] != ' ' || str[i] != '\t'))
		i++;
	return (i);
}

static int	check_split_echo(char ***tabl, int index)
{
	int 	i;
	int 	t;
	char	*tmp;

	i = 0;
	t = index + 1;
	tmp = NULL;
	debug(tabl);
	i = echap_quote((*tabl)[index], i, 0);
	if (i == 0)
		i = echap_word((*tabl)[index], i);
	if (i + 1 < ft_strlen((*tabl)[index]))
	{
		increase_tab(tabl);
		tmp = ft_strsub((*tabl)[index], 0, i);
		(*tabl)[t] = ft_strsub((*tabl)[index], i + 1, ft_strlen((*tabl)[index]) - (i + 1));
		ft_strdel(&(*tabl)[index]);
		(*tabl)[index] = ft_strdup(tmp);
		ft_strdel(&tmp);
		check_split_echo(tabl, index + 1);
	}
	return (0);
}

/*
**	Appleler via insert_cmd_simple.c
*/

char		**split_echo(char *str)
{
	int ret;
	char **new;
	char **tmp;

	new = NULL;
	tmp = NULL;
	ret = 0;
	if (ft_strstr(str, "\"") == NULL && ft_strstr(str, "\'") == NULL)
	{
		new = ft_strsplit(str, ' ');
		return (new);
	}
	if (str[4] == '\"')
	{
		basic_error(str, " : command not found\n");
		return (NULL);
	}
	if (!(new = (char **)malloc(sizeof(char *) * 3)))
		return (NULL);
	new[0] = ft_strdup("echo");
	new[1] = ft_strsub(str, 5, ft_strlen(str) - 5);
	new[2] = NULL;
	ret = check_split_echo(&new, 1);
	if (ret == 1)
		return (NULL);
	return (new);
}
