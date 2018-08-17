/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   kill_process.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/26 13:22:36 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/17 11:50:36 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

int				ft_kill_process(t_cmd *start)
{
	while (start)
	{
		kill(start->pid, 0);
		start = start->next;
	}
	return (0);
}
