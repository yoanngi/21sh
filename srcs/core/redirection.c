/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   redirection.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/11 09:36:12 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/22 09:51:39 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
**  Creer les differents fd et les retournes
*/

int			exec_redirection(t_path *file)
{
	int		fd;

	fd = 0;
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
	dup2(fd, file->redir_fd) == -1 ? basic_error("dup2", "failled") : 0;
    close(fd) == -1 ? basic_error("close", "failled") : 0;
	return (fd);
}

/*
**  execute la commande dans une redirection
*/

int			fork_redirection(t_cmd *lst)
{
	int		status;
	t_path	*lst_path;

	status = -1;
	lst_path = lst->pathname;
	while (lst->pathname)
	{
        lst->pathname->fd = exec_redirection(lst->pathname);
        lst->pathname = lst->pathname->next;
	}
    lst->pathname = lst_path;
	status = execve(lst->rep, lst->tab_cmd, lst->env);
	return (status);
}
