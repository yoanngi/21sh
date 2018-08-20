/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   split_echo.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/17 14:38:34 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/20 16:26:54 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void		resize_echo(char **tmp, char **str, int start, int end)
{
	char	*cpy;

	cpy = NULL;
	cpy = ft_strdup(*str);
	ft_strdel(str);
	if (cpy[start] == '\"' || cpy[start] == '\'')
		start++;
	if (cpy[end] == '\"' || cpy[end] == '\'')
		end--;
	*str = ft_strsub(cpy, start, end);
	if (end + 1 < ft_strlen(cpy))
		*tmp = ft_strsub(cpy, end + 1, ft_strlen(cpy) - (end + 1));
	else
		*tmp = NULL;
	ft_strdel(&cpy);
}

static char		*clear_quote_echo(char **str)
{
	char	*tmp;
	char	*cpy;
	int		i;

	tmp = NULL;
	cpy = NULL;
	i = 0;
	if (*str == NULL)
		return (NULL);
	if (!(cpy = ft_strdup(*str)))
		return (NULL);
	while (cpy[i] && cpy[i] != '\"' && cpy[i] != '\'' && cpy[i] != ' ')
		i++;
	if (cpy[i] == '\"' && i == 0)
	{
		i++;
		while (cpy[i] != '\"')
			i++;
	}
	else if (cpy[i] == '\'' && i == 0)
	{
		i++;
		while (cpy[i] != '\'')
			i++;
	}
	printf("i = %d\n", i);
	resize_echo(&tmp, str, 0, i);
	printf("*str = %s\n", *str);
	printf("tmp = %s\n", tmp);
	ft_strdel(&cpy);
	return (tmp);
}

static int		check_split_echo(char ***tabl, char *str)
{
	int		i;
	char	*tmp;

	i = 1;
	(*tabl)[0] = ft_strdup("echo");
	(*tabl)[1] = ft_strsub(str, 5, ft_strlen(str) - 5);
	tmp = NULL;
	while ((*tabl)[i])
	{
		printf("clear_line\n");
		clear_line(&(*tabl)[i]);
		printf("clear_quote\n");
		tmp = clear_quote_echo(&(*tabl)[i]);
		if (tmp != NULL)
			(*tabl)[i + 1] = ft_strdup(tmp);
		else
			return (0);
		ft_strdel(&tmp);
		i++;
	}
	ft_strdel(&tmp);
	return (0);
}

/*
**	Appleler via insert_cmd_simple.c
*/

char			**split_echo(char *str)
{
	int		i;
	int		j;
	char	**new;
	char	**tmp;

	i = 0;
	j = 0;
	new = NULL;
	tmp = NULL;
	if (ft_strstr(str, "\"") == NULL && ft_strstr(str, "\'") == NULL)
		new = ft_strsplit(str, ' ');
	else
	{

		tmp = ft_strsplit(str, ' ');
		i = ft_len_tab(tmp);
		tmp = ft_del_tab(tmp);
		if (i < 3)
			i = 3;
		if (!(new = (char **)malloc(sizeof(char *) * i)))
			return (NULL);
		while (j < i)
		{
			new[j] = NULL;
			j++;
		}
		check_split_echo(&new, str);
	}
	printf("end split echo (taille tab = %d)\n", i);
	return (new);
}
