/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   redirection.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/11 09:36:12 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/11 16:46:33 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int	len_list_redirection(t_path *lst)
{
	int		i;

	i = 0;
	if (lst == NULL)
		return (0);
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int			exec_redirection(t_cmd *lst, t_path *file, int *fd_in,
		int pipe_fd[2])
{
	int		fd;
	int		ret;

	fd = 0;
	ret = 0;
	if (file->name == NULL)
		return (-1);
	if (file->s_or_d == 2)
		fd = open(file->name, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP |
				S_IROTH);
	else if (file->s_or_d == 3)
		fd = open(file->name, O_CREAT | O_APPEND | O_WRONLY, S_IRUSR | S_IWUSR |
				S_IRGRP | S_IROTH);
	if (fd == -1)
		exit(EXIT_FAILURE);
	dup2(*fd_in, 0) == -1 ? basic_error("dup2", "failled") : 0;
	dup2(fd, 1) == -1 ? basic_error("dup2", "failled") : 0;
	close(pipe_fd[0]) == -1 ? basic_error("close", "failled") : 0;
	close(fd) == -1 ? basic_error("close", "failled") : 0;
	execve(lst->rep, lst->tab_cmd, lst->env);
	return (ret);
}

int			fork_redirection(t_cmd *lst, int pipe_fd[2],
		int *fd_in)
{
	int		status;
	int		pid;
	t_path	*lst_path;

	lst_path = lst->pathname;
	if (len_list_redirection(lst_path) == 1)
		return (exec_redirection(lst, lst->pathname, fd_in, pipe_fd));
	while (lst->pathname)
	{
		if ((pid = fork()) == -1)
		{
			ft_error_fork(pid);
			return (-1);
		}
		if (pid == 0)
			exec_redirection(lst, lst->pathname, fd_in, pipe_fd);
		else
		{
			lst->pathname->pid = pid;
			waitpid(pid, &status, 0);
			lst->pathname = lst->pathname->next;
		}
	}
	ft_kill_fork_path(lst_path);
	return (WEXITSTATUS(status));
}
