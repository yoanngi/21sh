/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   func_cd.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 13:21:57 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/24 13:48:35 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
**	Change directory
**	~ // - // $ > traiter dans parsing
*/

static int	change_directory(t_struct *data, t_cmd *lst, char *newpath)
{
	if (newpath != NULL)
	{
		if (chdir(newpath) == -1)
		{
			ft_putstr_fd("cd: no such file or directory: ", 2);
			ft_putstr_fd(newpath, 2);
			ft_putstr_fd("\n", 2);
			return (1);
		}
		actualise_env(data, newpath);
	}
	else
	{
		if (chdir(lst->tab_cmd[1]) == -1)
		{
			ft_putstr_fd("cd: no such file or directory: ", 2);
			ft_putstr_fd(lst->tab_cmd[1], 2);
			ft_putstr_fd("\n", 2);
			return (1);
		}
		actualise_env(data, lst->tab_cmd[1]);
	}
	return (0);
}

static int	check_error_cd(char **tabargv)
{
	int i;

	i = 0;
	while (tabargv[i])
		i++;
	if (i > 3)
	{
		ft_putstr_fd("cd: too many arguments\n", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	cd_minus(t_struct *data, t_cmd *lst)
{
	change_directory(data, lst, lst->tab_cmd[1]);
	return (0);
}

int			func_cd(t_struct *data, t_cmd *lst)
{
	int mode;

	mode = 0;
	if (!data || !lst)
		return (EXIT_FAILURE);
	if ((mode = check_error_cd(lst->tab_cmd)) == 1)
		return (EXIT_FAILURE);
	if (lst->tab_cmd[1] == NULL)
		change_directory(data, lst, data->home);
	else if (!ft_strcmp(lst->tab_cmd[1], "-"))
	{
		ft_strdel(&lst->tab_cmd[1]);
		lst->tab_cmd[1] = ft_strdup(data->oldpwd);
		cd_minus(data, lst);
	}
	else
		change_directory(data, lst, NULL);
	ft_strdel(&data->pwd);
	data->pwd = ft_return_pwd();
	return (EXIT_SUCCESS);
}
