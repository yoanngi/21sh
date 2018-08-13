/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   core_shell.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/06 10:11:53 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/11 16:47:43 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
**	parse_line : Parse la line et la convertit en liste chainer
**	Execute la / les commandes
*/

static t_ins		*what_next_link(t_ins *lst, int code)
{
	if (cmd_suivante(lst, code) == 0)
		return (lst->next);
	else
	{
		while (lst)
		{
			if (lst->code == 0)
				return (lst->next);
			lst = lst->next;
		}
	}
	return (NULL);
}

static int			parse_line(t_struct *data, char **line)
{
	int		ret;
	t_ins	*cpy;

	ret = 0;
	if (ft_check_line_vide(*line, &data) == 0)
		return (0);
	data->commandes = ft_split_commandes(line, data);
	// A DETETE **********************************************************
	ft_putstr_fd(GREEN, 2);
	ft_printf("Parsing ok\n");
	ft_putstr_fd(RESET, 2);
	// *******************************************************************
	cpy = data->commandes;
	while (cpy)
	{
		print_debug(&cpy->cmd, cpy->code);
		if (ft_check_arg_invalid(data, cpy->cmd) == 0)
		{
			ret = execute_commandes(data, cpy->cmd);
			if (ret == -1)
			{
				data->commandes = clear_ins(data->commandes);
				return (1);
			}
			data->code_erreur = ret;
		}
		// A DETETE **********************************************************
		ft_putstr_fd(GREEN, 2);
		ft_printf("******* Valeur de retour (data->code_erreur) = %d\n", data->code_erreur);
		ft_putstr_fd(RESET, 2);
		// *******************************************************************
		cpy = what_next_link(cpy, data->code_erreur);
	}
	data->commandes = clear_ins(data->commandes);
	return (0);
}

/*
**	Boucle infini, Attend un retour different de zero pour exit
*/

void				core_shell(t_struct *data)
{
	int		quit;
	t_hist	*tmp;
	char	*full_line;

	quit = 0;
	tmp = NULL;
	full_line = NULL;
	init_info(&g_info);
	while (quit == 0)
	{
		line_edit(&g_info, tmp);
		if (g_info.line != NULL && quit == 0)
		{
			if (g_info.quoted)
			{
				full_line = str_append(full_line, g_info.line);
				full_line = str_append(full_line, "\n");
				ft_strdel(&(g_info.line));
			}
			else
			{
				full_line = str_append(full_line, g_info.line);
				ft_strdel(&(g_info.line));
				default_term_mode(&g_info);
				// A DETETE **********************************************************
				ft_putstr_fd(GREEN, 2);
				printf("********************************************* LINE = |%s|***\n", full_line);
				ft_putstr_fd(RESET, 2);
				// *******************************************************************
				quit = parse_line(data, &(full_line));
				ft_strdel(&full_line);
			}
		}
		reinit_info(&g_info);
	}
	default_term_mode(&g_info);
}
