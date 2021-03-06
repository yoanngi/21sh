/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cut_copy_paste.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/25 13:50:09 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 12:48:55 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
** Copies the end of the command line from the
** cursor position
*/

static void	copy_end(t_info *info, t_hist *tmp)
{
	int		curs_pos;
	char	*tmp_str;
	int		i;

	i = 0;
	tmp_str = NULL;
	curs_pos = info->curs_in_str - 1;
	if (info->curs_in_str <= info->s_len)
	{
		if (!(tmp_str = malloc(ft_strlen(tmp->name) - curs_pos + 2)))
			exit(0);
		while (curs_pos < ft_strlen(tmp->name) + 1)
		{
			tmp_str[i] = tmp->name[curs_pos];
			i++;
			curs_pos++;
		}
		tmp_str[i] = 0;
		if (tmp_str)
			if (info->copy)
				ft_strdel(&(info->copy));
		info->copy = ft_strdup(tmp_str);
		ft_strdel(&tmp_str);
	}
}

/*
** Copies the beginning of the command line until the
** cursor position
*/

static void	copy_beginning(t_info *info, t_hist *tmp)
{
	int		curs_pos;
	char	*tmp_str;
	int		i;

	i = -1;
	tmp_str = NULL;
	curs_pos = info->curs_in_str - 2;
	if (info->curs_in_str > 1)
	{
		if (!(tmp_str = malloc(ft_strlen(tmp->name) + 1)))
			exit(0);
		while (i++ < curs_pos)
			tmp_str[i] = tmp->name[i];
		tmp_str[i] = 0;
		if (info->copy)
			ft_strdel(&(info->copy));
		info->copy = ft_strdup(tmp_str);
		ft_strdel(&tmp_str);
	}
}

/*
** Copies and cuts the end of the command line from the
** cursor position
*/

static void	cut_end(t_info *info, t_hist *tmp)
{
	int		curs_pos;

	curs_pos = info->curs_in_str;
	copy_end(info, tmp);
	end_key(info);
	while (info->curs_in_str > curs_pos)
		del_char(info, tmp);
}

/*
** Copies and cuts the beginning of the command line
** until the cursor position
*/

static void	cut_beginning(t_info *info, t_hist *tmp)
{
	int	i;

	copy_beginning(info, tmp);
	i = ft_strlen(info->copy) + 1;
	while (i)
	{
		del_char(info, tmp);
		i--;
	}
}

/*
** Manages the cut and copy signals
*/

void		cut_n_cpy(t_info *info, char *buff, t_hist *tmp)
{
	int	i;

	i = 0;
	if (KEY_CODE_CTRL_E && tmp->name)
		copy_end(info, tmp);
	if (KEY_CODE_CTRL_X && tmp->name)
		cut_end(info, tmp);
	if (KEY_CODE_CTRL_A && tmp->name)
		cut_beginning(info, tmp);
	if (KEY_CODE_CTRL_B && tmp->name)
		copy_beginning(info, tmp);
	if (KEY_CODE_CTRL_P && info->copy)
		while (info->copy[i])
		{
			info->curs_in_str <= info->s_len ?
				insert_char(info->copy[i], info, tmp)
				: add_char(info->copy[i], info, tmp);
			i++;
		}
}
