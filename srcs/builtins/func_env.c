/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   func_env.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 13:22:16 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/10 15:31:48 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
**	Check si str et hash son valide
*/

static int		ft_is_func(t_struct *data, char *str, int hash)
{
	char		*tmp;

	tmp = NULL;
	if (!(data->tab_hash) || hash == 0)
		return (1);
	if (data->tab_hash[hash] != 0)
	{
		tmp = ft_search_path(str, data);
		if (tmp == NULL)
		{
			ft_strdel(&tmp);
			return (1);
		}
		ft_strdel(&tmp);
		return (0);
	}
	return (1);
}

/*
**	Execute commande
*/

int				execute_with_env(t_struct **data, t_cmd *lst, int i, int opt)
{
	char		**new;
	int			cpy;
	int			j;

	new = NULL;
	cpy = i;
	j = 0;
	while (lst->tab_cmd[cpy])
		cpy++;
	if (!(new = (char **)malloc(sizeof(char *) * (cpy - i + 1))))
		return (1);
	while (lst->tab_cmd[i])
	{
		new[j] = ft_strdup(lst->tab_cmd[i]);
		i++;
		j++;
	}
	new[j] = NULL;
	lst->tab_cmd = ft_del_tab(lst->tab_cmd);
	lst->tab_cmd = ft_duplicate_tab(new);
	new = ft_del_tab(new);
	ft_strdel(&lst->rep);
	chose_rep(*data, &lst, 1);
	if (opt == 1)
		lst->env = ft_del_tab(lst->env);
	if (ft_check_arg_invalid(*data, lst) == 1)
		return ((*data)->code_erreur);
	j = ft_process(lst);
	return (j);
}

/*
**	Print env ou execute commande avec env modifier
*/

static int		print_env(t_struct *data, t_cmd *lst, int i, int opt)
{
	int		j;
	int		ret;

	j = i;
	ret = 0;
	while (lst->tab_cmd[j])
	{
		if (ft_strstr(lst->tab_cmd[j], "=") == NULL && lst->tab_cmd[j] != NULL)
		{
			ret = execute_var_modif(data, &lst, i, opt);
			return (ret);
		}
		j++;
	}
	if (opt == 0)
		ft_print_tab(data->env);
	while (lst->tab_cmd[i])
	{
		ft_putendl(lst->tab_cmd[i]);
		i++;
	}
	return (0);
}

/*
**	Suite env
*/

static int		func_env_suite(t_struct **data, t_cmd *lst, int i, int opt)
{
	int		hash;
	int		ret;

	hash = 0;
	ret = 0;
	if (opt == 1 && lst->tab_cmd[i] == NULL)
		return (0);
	while (lst->tab_cmd[i])
	{
		hash = ft_calcul_hash(lst->tab_cmd[i], (*data)->sizemax);
		if (ft_is_func(*data, lst->tab_cmd[i], hash) == 0)
		{
			ret = execute_with_env(data, lst, i, opt);
			return (ret);
		}
		if (ft_strstr(lst->tab_cmd[i], "=") != NULL)
		{
			ret = print_env(*data, lst, i, opt);
			return (ret);
		}
		else
		{
			ft_error_dir("env: ", lst->tab_cmd[i], lst->stderr_cmd);
			return (1);
		}
		i++;
	}
	return (1);
}

/*
**	Core env
*/

int				func_env(t_struct *data, t_cmd *lst)
{
	int		i;
	int		ret;
	int		option_i;
	int		exit;

	i = 0;
	ret = 0;
	option_i = 0;
	exit = 0;
	while (exit == 0)
	{
		if (lst->tab_cmd[i] == NULL)
		{
			ft_print_tab(data->env);
			return (0);
		}
		else if (ft_strcmp(lst->tab_cmd[i], "env") != 0)
			exit = 1;
		else
			i++;
	}
	if (ft_strcmp(lst->tab_cmd[i], "-i") == 0)
	{
		option_i = 1;
		i++;
	}
	ret = func_env_suite(&data, lst, i, option_i);
	return (ret);
}
