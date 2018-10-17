/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   end_quote.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/23 13:43:07 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/09/05 17:47:55 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
** Checks if there is an unclosed single quote.
*/

static void	single_toggle(t_info *info)
{
	if (!(info->quoted))
		info->quoted = 1;
	else
		info->quoted = 0;
}

/*
** Checks if there is an unclosed double quote.
*/

static void	double_toggle(t_info *info)
{
	if (!(info->quoted))
		info->quoted = 2;
	else
		info->quoted = 0;
}

/*
** Checks if there is an unclosed quote of
** any type. Modifies the prompt accordingly.
*/

void		toggle_quote(t_info *info)
{
	int	i;

	i = 0;
	if (info->line)
		while (info->line[i])
		{
			if (((i == 0 && info->line[i] == '"') || (i > 0
			&& info->line[i] == '"' && info->quoted != 4
				&& info->line[i - 1] != '\\')) && info->quoted != 1)
				double_toggle(info);
			if (((i == 0 && info->line[i] == 39) ||
			(i > 0 && info->line[i] == 39 && info->quoted != 4
			&& info->line[i - 1] != '\\')) && info->quoted != 2)
				single_toggle(info);
			i++;
		}
	if (last_char(info->line) == '\\' && info->quoted != 1 && info->quoted != 2)
		info->quoted = 3;
	else if (ft_strstr(info->line, "<<"))
		info->quoted = 4;
	else
		info->quoted = 0;
	change_prompt(info, info->quoted);
}
