/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:30:31 by yel-aoun          #+#    #+#             */
/*   Updated: 2022/10/08 17:49:29 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

int	ft_exist_export(char **env, char *find)
{
	int		i;
	int		k;
	char	**str;

	i = 0;
	k = 0;
	while (env[i])
	{
		str = ft_split(env[i], '=');
		k = ft_is_longer(str[0], find);
		if (ft_strncmp (str[0], find, k) == 0)
		{
			ft_free(str);
			return (1);
		}
		i++;
		ft_free(str);
	}
	return (0);
}

int	ft_exist_env(char **env, char *find)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp ((env[i]), find, ft_strlen(find)) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

char	**ft_add_env(t_shell *shell, char **env, char *str)
{
	char	**new;
	char	**splt;
	char	**s_p;
	int		j;
	int		k;

	j = 0;
	k = 0;
	splt = ft_split(str, '=');
	s_p = ft_split(splt[0], '+');
	j = ft_exist_export(env, s_p[0]);
	ft_free(s_p);
	if (j == 1)
	{
		k = ft_search(splt[0], '+');
		if (k == 1)
			new = ft_join_env(shell, str);
		else
			new = ft_up_env(shell, str);
	}
	else
		new = ft_add_env_help(env, str);
	ft_free(env);
	ft_free(splt);
	return (new);
}

char	**ft_add_export(t_shell *shell, char **env, char *str)
{
	char	**new;
	char	**splt;
	char	**s_p;
	int		j;

	j = 0;
	splt = ft_split(str, '=');
	s_p = ft_split(splt[0], '+');
	j = ft_exist_export(env, s_p[0]);
	if (j == 1)
		new = ft_add_export_help1(shell, splt[0], str);
	else
		new = ft_add_export_help2(env, str);
	if (j == 0)
		ft_free(shell->export);
	ft_free (splt);
	ft_free (s_p);
	return (new);
}
