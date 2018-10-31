/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_error_suite.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/31 14:51:46 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/31 14:54:12 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

void		error_parsing(char *str, int i)
{
	ft_putstr_fd("21sh : parse error near `", 2);
	ft_putchar_fd(str[i], 2);
	ft_putstr_fd("'\n", 2);
	change_prompt(&g_info, 0);
}
