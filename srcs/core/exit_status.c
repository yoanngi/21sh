/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exit_status.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/21 13:54:47 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/21 16:43:44 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

int		exit_status(int status)
{
	int		code;

	code = 0;
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
	{
		code = WTERMSIG(status);
		if (code == 11)
		{
			ft_putstr_fd("Segmentation fault: 11\n", 2);
		}
		return (code + 128);
	}
	return (0);
}
