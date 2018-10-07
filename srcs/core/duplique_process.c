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
	    dup2(*fd_in, lst->stdin_cmd) == -1 ? basic_error("dup2", "HEre failled") : 0;
	    dup2(pipe_fd[1], lst->stdout_cmd) == -1 ?
    basic_error("dup2", "la failled") : 0;
        if (lst->heredoc != NULL || lst->heredoc_str != NULL)
	        return (fork_heredoc(lst, 0));
        if (lst->pathname != NULL)
	        return (fork_redirection(lst));
    }
    else
        wait(NULL);
    return (0);
}
