/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   echap_quote.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 10:24:57 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/24 11:32:55 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
**  Echap quote or dauote in str
*/

static int	echap_back_slash(char *str, int i)
{
	if (str[i] == '\\')
	{
		i++;
		if (str[i] == '\\')
			return (i);
		while (str[i] && (str[i] != ' ' || str[i] != '\t'))
			i++;
	}
	return (i);
}

static int	check_return(char *str, int i)
{
	int		len;

	len = ft_strlen(str);
	if (i < len)
		return (i + 1);
	return (len);
}

static int	boucle_echap(char *str, int i, char c)
{
	while (str[i])
	{
		if (str[i] == c && str[i - 1] != '\\')
			return (i);
		i++;
	}
	return (i);
}

int			echap_quote(char *str, int i, int opt)
{
	if (!(str))
		return (0);
	if (str[i] == '\0' || str[i + 1] == '\0')
		return (i);
	if (str[i] == '\'')
	{
		i++;
		i = boucle_echap(str, i, '\'');
		return (check_return(str, i));
	}
	else if (str[i] == '\"')
	{
		i++;
		i = boucle_echap(str, i, '\"');
		return (check_return(str, i));
	}
	if (opt == 1)
		i = echap_back_slash(str, i);
	return (i);
}
