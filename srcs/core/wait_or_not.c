/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wait_or_not.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/23 13:09:39 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 13:28:01 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

int		wait_or_not(int *status, pid_t pid, t_cmd *start)
{
	int		stat;
	int		k;

	stat = 0;
	k = 0;
	waitpid(pid, status, WUNTRACED);
	while (start)
	{
		k = waitpid(start->pid, &stat, WNOHANG);
		if (k != -1)
			kill(start->pid, SIGPIPE);
		start = start->next;
	}
	return (0);
}
