/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_close.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/17 11:23:30 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/17 13:09:20 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

int			ft_close(int fd_out, int fd_err)
{
	if (fd_out != 0)
	{
		if (close(fd_out) == -1)
			ft_putstr_fd("une erreur c'est produite\n", 2);
	}
	if (fd_err != 0)
	{
		if (close(fd_err) == -1)
			ft_putstr_fd("une erreur c'est produite\n", 2);
	}
	return (0);
}

/*
**  >&
*/

int         check_agregateur(int stdcmd, int fd_ref)
{
	char	*name_fd;
	int		fd;

	printf("%s\n", __func__);
	name_fd = NULL;
	fd = 0;
	if (stdcmd != fd_ref)
	{
	/*	name_fd = ttyname(stdcmd);
		fd = open(name_fd, O_RDWR);
		dup2(fd_ref, fd);
		if (close(fd_ref) == -1)
			ft_putstr_fd("Une erreur c'est produite (close)\n", 2);
	*/
		dup2(fd_ref, stdcmd);
		return (fd);
	}
	printf("no agreg\n");
	return (0);
}
