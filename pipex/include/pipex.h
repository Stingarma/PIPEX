/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:21:54 by lsaumon           #+#    #+#             */
/*   Updated: 2024/05/14 15:01:24 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_pipex
{
	char	**cmd_arg1;
	char	**cmd_arg2;
	char	*cmd_path1;
	char	*cmd_path2;
	int		fd_infile;
	int		fd_outfile;
	int		tab[2];
	pid_t	pid1;
	pid_t	pid2;
}t_pipex;

//====== MAIN ======//
void	pipex_init(char **argv, char **env, t_pipex *pipex);
void	first_child(t_pipex *pipex, char **env);
void	second_child(t_pipex *pipex, char **env);

//====== UTILS ======//

char	*search_line(char **env);
char	*cmd_path(char *cmd, char **env);
void	free_double_tab(char **tab);
void	ft_free_all(t_pipex *pipex);

//====== UTILS_2 ======//

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		word_count(char *str, char sep);
char	**ft_split(char *str, char sep);

//====== UTILS_3 ======//

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
void	forking_2(t_pipex pipex, char **env);
void	forking_1(t_pipex pipex, char **env);

#endif