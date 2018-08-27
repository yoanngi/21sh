/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wait_or_not.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/23 13:09:39 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/27 12:49:12 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

int		wait_or_not(int *status, pid_t pid)
{
	waitpid(pid, status, 0);
	// a modif
	// ne marche pas avec top | head
	printf("Re wait\n");
	while (wait(0) > 0)
		;
	printf("End wait\n");
	return (0);
}
