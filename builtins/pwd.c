/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:44:19 by yel-aoun          #+#    #+#             */
/*   Updated: 2022/09/11 10:26:57 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

void	ft_put_pwd(void)
{
	char	*s;

	s = getcwd(NULL, 0);
	write (1, s, strlen(s));
	write (1, "\n", 1);
}