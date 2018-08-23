/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   redirection_fd.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/23 11:22:16 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/23 13:01:03 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

int			redirection_fd(t_cmd *data)
{
	printf("%s (pid = %d)\n", __func__, getpid());
	if (data->stdout_cmd != 1)
	{
		printf("stdout != 1\n");
		dup2(data->stdout_cmd, 1);
	}
	if (data->stderr_cmd != 2)
	{
		printf("stderr != 2\n");
		dup2(data->stderr_cmd, 2);
	}
	return (0);
}
