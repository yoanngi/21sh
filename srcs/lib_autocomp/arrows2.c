/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   arrows2.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/28 17:50:15 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 15:01:49 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void	ac_right2(t_info *info, t_slct *slct, t_hist *hist, t_slct *tmp)
{
	int		cols;

	cols = info->col_nb / (info->max_len + 2);
	erase_prev(info, hist);
	tmp->current = 0;
	if (tmp->index % cols != 0 && tmp->next != slct)
	{
		tmp->next->current = 1;
		add_slct(tmp->next, info);
	}
	else
	{
		while (tmp->index % cols != 1)
			tmp = tmp->prev;
		tmp->current = 1;
		add_slct(tmp, info);
	}
}

/*
** Goes one column to the right.
*/

void		ac_right_key(t_info *info, t_slct *slct, t_hist *hist)
{
	t_slct	*tmp;

	if (slct_current(slct, info, hist))
		return ;
	tmp = ac_first_elem(slct);
	while (tmp != slct)
	{
		if (tmp->current)
		{
			ac_right2(info, slct, hist, tmp);
			return ;
		}
		tmp = tmp->next;
	}
}

static void	ac_left2(t_info *info, t_slct *slct, t_hist *hist, t_slct *tmp)
{
	int		cols;
	int		rows;

	rows = get_row_number(info);
	cols = info->col_nb / (info->max_len + 2);
	erase_prev(info, hist);
	tmp->current = 0;
	if (tmp->index % cols != 1)
	{
		tmp->prev->current = 1;
		add_slct(tmp->prev, info);
	}
	else
	{
		if (info->nb_elem - tmp->index > cols)
			while (tmp->index % cols != 0 || tmp == slct)
				tmp = tmp->next;
		else
			while (tmp->next != slct)
				tmp = tmp->next;
		tmp->current = 1;
		add_slct(tmp, info);
	}
}

/*
** Goes one column to the left.
*/

void		ac_left_key(t_info *info, t_slct *slct, t_hist *hist)
{
	t_slct	*tmp;

	if (slct_current(slct, info, hist))
		return ;
	tmp = ac_last_elem(slct);
	while (tmp != slct)
	{
		if (tmp->current)
		{
			ac_left2(info, slct, hist, tmp);
			return ;
		}
		tmp = tmp->prev;
	}
}
