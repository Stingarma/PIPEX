/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:22:30 by lsaumon           #+#    #+#             */
/*   Updated: 2024/05/14 15:36:19 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*search_line(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
		{
			return (env[i] + 5);
		}
		i++;
	}
	return (NULL);
}

char	*cmd_path(char *cmd, char **env)
{
	char	**all_paths;
	char	*manip;
	char	*final_path;
	int		i;

	i = 0;
	all_paths = ft_split(search_line(env), ':');
	while (all_paths[i])
	{
		manip = ft_strjoin(all_paths[i], "/");
		final_path = ft_strjoin(manip, cmd);
		free(manip);
		if (access(final_path, F_OK | X_OK) == 0)
		{
			free_double_tab(all_paths);
			return (final_path);
		}
		free(final_path);
		i++;
	}
	free_double_tab(all_paths);
	free(final_path);
	return (NULL);
}

void	free_double_tab(char **tab)
{
	int		i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

void	ft_free_all(t_pipex *pipex)
{
	free(pipex->cmd_path1);
	free(pipex->cmd_path2);
	free_double_tab(pipex->cmd_arg1);
	free_double_tab(pipex->cmd_arg2);
	close(pipex->fd_infile);
	close(pipex->fd_outfile);
}
