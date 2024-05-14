/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:59:04 by lsaumon           #+#    #+#             */
/*   Updated: 2024/04/24 16:26:52 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
	{
		return (0);
	}
	while ((s1[i] && s2[i]) && (s1[i] == s2[i]) && i < (n - 1))
		i++;
	if (n < 1)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s1;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	s1 = malloc(sizeof(char) * len + 1);
	if (!s1)
		return (NULL);
	ft_strlcpy(s1, s + start, len + 1);
	return (s1);
}

int	word_count(char *str, char sep)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == sep))
			i++;
		if (str[i])
			wc++;
		while (str[i] && str[i] != sep)
			i++;
	}
	return (wc);
}

char	**ft_split(char *str, char sep)
{
	char	**out;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	out = malloc(sizeof(char *) * (word_count(str, sep) + 1));
	if (!out)
		return (NULL);
	out[word_count(str, sep)] = NULL;
	while (str[i] && k < word_count(str, sep))
	{
		while (str[i] && (str[i] == sep))
			i++;
		j = i;
		while (str[i] && str[i] != sep)
			i++;
		out[k] = ft_substr(str, j, i - j);
		k++;
	}
	return (out);
}
