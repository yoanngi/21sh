/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wait_or_not.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/23 13:09:39 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/30 13:52:27 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

int		wait_or_not(int *status, pid_t pid, t_cmd *start)
{
	int		*pipe_fd[2];

	waitpid(pid, status, 0);
	while (start)
	{
		*pipe_fd = (int *)start->pipe;
		close(*pipe_fd[0]);
		close(*pipe_fd[1]);
		start = start->next;
	}
	while (wait(0) > 0)
		;
	return (0);
}
