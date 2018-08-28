/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_process.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/13 15:38:15 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/28 13:33:18 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
**	Fonction pour une execution simple d'une commande
**	return : Valeur de retour de la commande
*/

int				ft_process(t_cmd *data)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid < 0)
	{
		ft_error_fork(pid);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		redirection_fd(data);
		if (execve(data->rep, data->tab_cmd, data->env) == -1)
			kill(data->pid, SIGTERM);
	}
	else
	{
		data->pid = pid;
		waitpid(pid, &status, 0);
	}
	return (exit_status(status));
}
