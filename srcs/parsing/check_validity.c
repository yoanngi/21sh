/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_validity.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/11 09:42:47 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/11 10:43:52 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

int				check_link(t_cmd *lst)
{
	if (lst->op_next == 1 && lst->pathname != NULL)
		return (1);
	if (lst->op_next == 2 && lst->pathname == NULL)
		return (1);
	return (0);
}

int				check_validity(t_cmd **lst, t_struct *data)
{
	t_cmd	*start;

	if (!(*lst))
		return (1);
	start = *lst;
	while (start)
	{
		if (check_link(start) != 0)
		{
			*lst = clear_cmd(*lst);
			ft_putstr_fd("21sh: invalid command\n", 2);
			data->code_erreur = 1;
			return (1);
		}
		start = start->next;
	}
	return (0);
}
