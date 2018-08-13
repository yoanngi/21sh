/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   redirections_avancees.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/17 10:54:14 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/11 15:29:11 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void		print_error_red(int before, int next)
{
	if (before != 1 && before != 2)
	{
		ft_putstr_fd("21sh: ", 2);
		ft_putnbr_fd(before, 2);
		ft_putstr_fd(": bad file descriptor\n", 2);
		return ;
	}
	if (next != 1 && next != 2)
	{
		ft_putstr_fd("21sh: ", 2);
		ft_putnbr_fd(next, 2);
		ft_putstr_fd(": bad file descriptor\n", 2);
		return ;
	}
}

static int		insert_next(char *str, int i)
{
	if (i + 1 == ft_strlen(str))
		return (1);
	else
	{
		if (str[i] == '&' && ft_isdigit(str[i + 1]) == 0)
			return ((int)str[i + 1] - 48);
		if (str[i] == '>' && ft_isdigit(str[i + 2]) == 0)
			return ((int)str[i + 2] - 48);
	}
	return (0);
}

static int		insert_before(char *str, int i)
{
	if (i == 0)
		return (1);
	else
	{
		if (str[i] == '>' && ft_isdigit(str[i - 1]) == 0)
			return ((int)str[i - 1] - 48);
		if (str[i] == '&' && ft_isdigit(str[i - 2]) == 0)
			return ((int)str[i - 2] - 48);
	}
	return (0);
}

int				ft_redirection_avancees(t_cmd **lst, char *str, int i)
{
	int		before;
	int		next;

	printf("%s\n", __func__);
	before = insert_before(str, i);
	printf("BEFORE = %d\n", before);
	next = insert_next(str, i);
	printf("NEXT = %d\n", next);
	print_error_red(next, before);
	if (before == 1)
	{
		(*lst)->stdout_cmd = next;
	}
	else if (before == 2)
	{
		(*lst)->stderr_cmd = next;
	}
	return (0);
}
