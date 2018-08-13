/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   func_env_suite.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/25 13:36:26 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/07/28 16:46:20 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
**	Execute une commande avec env modifier
*/

static int		ft_existe_in_env(char *str, char **env, int mode)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[len] && str[len] != '=')
		len++;
	if (mode == 0)
		len--;
	while (env[i])
	{
		if (ft_strncmp(env[i], str, len) == 0)
		{
			if (mode == 1)
				return (i);
			return (0);
		}
		i++;
	}
	if (mode == 1)
		return (0);
	return (1);
}

static int		malloc_for_env_suite(char ***str, t_struct *data, t_cmd *lst,
	int i)
{
	int		j;
	int		ret;

	j = 0;
	ret = 0;
	while (data->env[j])
	{
		if (!((*str)[j] = ft_strdup(data->env[j])))
			return (1);
		j++;
	}
	i = 0;
	while (lst->tab_cmd[i] && (ft_strcmp(lst->tab_cmd[i], "env") == 0 ||
	ft_strcmp(lst->tab_cmd[i], "-i") == 0))
		i++;
	while (lst->tab_cmd[i] && ft_strstr(lst->tab_cmd[i], "=") != NULL)
	{
		if ((ret = ft_existe_in_env(lst->tab_cmd[i], data->env, 1)) != 0)
		{
			ft_strdel(&(*str)[ret]);
			if (!((*str)[ret] = ft_strdup(lst->tab_cmd[i])))
				return (1);
		}
		else
		{
			if (!((*str)[j] = ft_strdup(lst->tab_cmd[i])))
				return (1);
		}
		i++;
		j++;
		if (lst->tab_cmd[i] == NULL)
			return (0);
	}
	return (0);
}

static char		**malloc_for_env_deux(t_struct **data, t_cmd **lst, int i)
{
	char		**new;
	int			len;
	int			x;

	new = NULL;
	len = 0;
	x = 0;
	while ((*data)->env[len])
		len++;
	len += (i + 1);
	if (!(new = (char **)malloc(sizeof(char *) * len)))
		return (NULL);
	if (malloc_for_env_suite(&new, *data, *lst, 1) == 1)
	{
		new = ft_del_tab(new);
		return (NULL);
	}
	new[len - 1] = NULL;
	return (new);
}

static char		**malloc_for_env(t_struct **data, t_cmd **lst, int i,
	int opt)
{
	char		**new;
	int			len;
	int			x;

	new = NULL;
	len = 0;
	x = 0;
	if (opt == 1)
	{
		len = i + 1;
		if (!(new = (char **)malloc(sizeof(char *) * len)))
			return (NULL);
		i = 0;
		while (ft_strcmp((*lst)->tab_cmd[i], "env") == 0 ||
	ft_strcmp((*lst)->tab_cmd[i], "-i") == 0)
			i++;
		while ((*lst)->tab_cmd[i] && ft_strstr((*lst)->tab_cmd[i], "=") != NULL)
		{
			new[x] = ft_strdup((*lst)->tab_cmd[i]);
			i++;
			x++;
		}
		new[len - 1] = NULL;
	}
	else
		new = malloc_for_env_deux(data, lst, i);
	return (new);
}

int				execute_var_modif(t_struct *data, t_cmd **lst, int i, int opt)
{
	int		j;
	int		backup_i;
	int		ret;
	char	**new;

	backup_i = i;
	ret = 0;
	j = 0;
	new = NULL;
	while ((*lst)->tab_cmd[i] && ft_strstr((*lst)->tab_cmd[i], "=") != NULL)
	{
		if (ft_existe_in_env((*lst)->tab_cmd[i], data->env, 0) == 1)
			j++;
		i++;
	}
	new = malloc_for_env(&data, lst, j, opt);
	if (new == NULL)
		return (1);
	(*lst)->env = ft_del_tab((*lst)->env);
	(*lst)->env = ft_duplicate_tab(new);
	new = ft_del_tab(new);
	ret = execute_with_env(&data, *lst, i, 0);
	return (ret);
}
