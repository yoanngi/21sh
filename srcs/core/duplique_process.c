/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   duplique_process.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/11 09:36:12 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/09/05 11:03:39 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

int      duplique_process(t_cmd *lst, int pipe_fd[2], int *fd_in)
{
    int     pid;

    pid = fork();
    if (pid == -1)
        return (1);
    if (pid == 0)
    {
	    dup2(*fd_in, lst->stdin_cmd) == -1 ? basic_error("dup2", "failled") : 0;
	    dup2(pipe_fd[0], lst->stdout_cmd) == -1 ?
    basic_error("dup2", "failled") : 0;
    	close(pipe_fd[1]) == -1 ? basic_error("close", "failled") : 0;
	    return (fork_redirection(lst));
    }
    else
        wait(NULL);
    return (0);
}