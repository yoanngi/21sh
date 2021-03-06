/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   keys.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/12 14:39:02 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 15:50:05 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
** Gets the cursor back to x = 0
*/

void		cursor_start(t_info *info)
{
	while (info->curs_x > 1)
	{
		tputs(tgetstr("le", NULL), 1, ft_putchar_err);
		get_curs_pos(info);
	}
}

/*
** Validates the command line and sends it to be
** executed.
*/

void		rc_key(t_info *info, t_hist *tmp)
{
	fill_history(info, tmp);
	toggle_quote(info);
	tputs(tgetstr("vi", NULL), 1, ft_putchar_err);
	end_key(info);
	tputs(tgetstr("sf", NULL), 1, ft_putchar_err);
	cursor_start(info);
	tputs(tgetstr("ve", NULL), 1, ft_putchar_err);
	get_curs_pos(info);
	info->loop = 0;
}

static void	get_key2(t_info *info, t_hist *tmp, char *buff)
{
	if (A_RGHT)
		alt_right(info, tmp);
	else if (A_LFT)
		alt_left(info, tmp);
	else if (KEY_CODE_BSP)
		del_char(info, tmp);
	else if (KEY_CODE_HOME)
		home_key(info);
	else if (KEY_CODE_END)
		end_key(info);
	else if (KEY_CODE_RC)
		rc_key(info, tmp);
	else if (KEY_CODE_CTRL_E || KEY_CODE_CTRL_B ||
			KEY_CODE_CTRL_X || KEY_CODE_CTRL_A || KEY_CODE_CTRL_P)
		cut_n_cpy(info, buff, tmp);
	else if (KEY_CODE_CTRL_D)
		ctrl_d(info, tmp);
	else if (KEY_CODE_TAB)
		autocomp(info, tmp);
	else if (ft_isprint(*buff))
		info->curs_in_str <= info->s_len ? insert_char(*buff, info, tmp)
			: add_char(*buff, info, tmp);
}

/*
** Gets the key that is typed.
*/

void		get_key(t_info *info, t_hist *tmp)
{
	char	buff[5];

	if (info->line)
		ft_strdel(&(info->line));
	if (tmp->name != NULL)
		info->line = ft_strdup(tmp->name);
	ft_bzero(buff, 5);
	get_curs_pos(info);
	while (!tmp->current)
		tmp = tmp->next;
	if ((read(0, buff, 4) < 0))
		exit(1);
	if (KEY_CODE_UP)
		up_key(info, tmp);
	else if (KEY_CODE_DOWN)
		down_key(info, tmp);
	else if (KEY_CODE_RIGHT)
		right_key(info);
	else if (KEY_CODE_LEFT)
		left_key(info);
	else if ((ALT_UP) || (A_DWN))
		alt_up_down(info, buff);
	else
		get_key2(info, tmp, buff);
}
