/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   kill_process.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/26 13:22:36 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/27 12:54:17 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

int				ft_kill_process(t_cmd *start)
{
	while (start)
	{
		kill(start->pid, SIGTERM);
		if (start->stdout_cmd != 1 && start->stdout_cmd != 2)
			close(start->stdout_cmd);
		if (start->stderr_cmd != 2 && start->stdout_cmd != 1)
			close(start->stderr_cmd);
		start = start->next;
	}
	return (0);
}
