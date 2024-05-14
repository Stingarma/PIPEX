/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:51:13 by lsaumon           #+#    #+#             */
/*   Updated: 2024/05/14 15:00:28 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	forking_1(t_pipex pipex, char **env)
{
	pipex.pid1 = fork();
	if (pipex.pid1 == -1)
	{
		write(2, "Error with fork", 15);
		ft_free_all(&pipex);
		exit(EXIT_FAILURE);
	}
	else if (pipex.pid1 == 0)
		first_child(&pipex, env);
}

void	forking_2(t_pipex pipex, char **env)
{
	pipex.pid2 = fork();
	if (pipex.pid2 == -1)
	{
		write(2, "Error with fork", 15);
		ft_free_all(&pipex);
		exit(EXIT_FAILURE);
	}
	else if (pipex.pid2 == 0)
		second_child(&pipex, env);
}
