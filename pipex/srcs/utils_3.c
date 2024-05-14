/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:12:29 by lsaumon           #+#    #+#             */
/*   Updated: 2024/04/24 16:51:48 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s)
{
	char	*tableau;
	int		i;

	i = 0;
	tableau = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!tableau)
		return (NULL);
	while (s[i] != '\0')
	{
		tableau[i] = s[i];
		i++;
	}
	return (tableau);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	len_result;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	len_result = len_s1 + len_s2;
	result = malloc(sizeof(char) * len_result + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, len_s1 + 1);
	ft_strlcat(result, s2, len_result + 1);
	return (result);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	i;

	if (!size && !dst)
		return (0);
	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	dest_len = ft_strlen(dst);
	i = 0;
	while (src[i] != '\0' && dest_len + 1 < size)
	{
		dst[dest_len] = src[i];
		dest_len++;
		i++;
	}
	dst[dest_len] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[i]));
}
