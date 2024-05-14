/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:21:34 by lsaumon           #+#    #+#             */
/*   Updated: 2024/05/14 15:39:11 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex		pipex;

	if (argc != 5)
		return (write(1, "Bad arguments", 13));
	if (env == NULL || env[0] == NULL)
	{
		write(2, "No environment variables available", 34);
		exit(EXIT_FAILURE);
	}
	pipex_init(argv, env, &pipex);
	forking_1(pipex, env);
	forking_2(pipex, env);
	close(pipex.tab[1]);
	close(pipex.tab[0]);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	ft_free_all(&pipex);
	return (0);
}

void	pipex_init(char **argv, char **env, t_pipex *pipex)
{
	pipex->fd_infile = open(argv[1], O_RDONLY);
	if (pipex->fd_infile < 0)
	{
		write(2, "Error openning infile", 21);
		exit(EXIT_FAILURE);
	}
	pipex->fd_outfile = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0666);
	if (pipex->fd_outfile < 0)
	{
		write(2, "Error creating outfile", 22);
		close(pipex->fd_infile);
		exit(EXIT_FAILURE);
	}
	if (pipe(pipex->tab) == -1)
	{
		write(2, "Error with pipe", 15);
		close(pipex->fd_infile);
		close(pipex->fd_outfile);
		exit(EXIT_FAILURE);
	}
	pipex->cmd_arg1 = ft_split(argv[2], ' ');
	pipex->cmd_arg2 = ft_split(argv[3], ' ');
	pipex->cmd_path1 = cmd_path(pipex->cmd_arg1[0], env);
	pipex->cmd_path2 = cmd_path(pipex->cmd_arg2[0], env);
}

void	first_child(t_pipex *pipex, char **env)
{
	close(pipex->tab[0]);
	dup2(pipex->fd_infile, STDIN_FILENO);
	dup2(pipex->tab[1], STDOUT_FILENO);
	if (execve(pipex->cmd_path1, pipex->cmd_arg1, env) == -1)
	{
		write(2, "Error executing first command", 29);
		ft_free_all(pipex);
		exit(EXIT_FAILURE);
	}
}

void	second_child(t_pipex *pipex, char **env)
{
	close(pipex->tab[1]);
	dup2(pipex->fd_outfile, STDOUT_FILENO);
	dup2(pipex->tab[0], STDIN_FILENO);
	if (execve(pipex->cmd_path2, pipex->cmd_arg2, env) == -1)
	{
		write(2, "Error executing second command", 30);
		ft_free_all(pipex);
		exit(EXIT_FAILURE);
	}
}
