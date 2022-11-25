/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:52:37 by vlepille          #+#    #+#             */
/*   Updated: 2022/11/25 17:52:37 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_linelen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	i += str[i] == '\n';
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	size_t			res;

	i = 0;
	if (dest)
	{
		res = ft_strlen(src) + ft_strlen(dest);
		while (dest[i] && i < size)
			i++;
		j = 0;
	}
	if (i >= size)
		return (ft_strlen(src) + size);
	while (src[j] && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (res);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int		i;
	const unsigned int	lsrc = ft_strlen(src);

	if (!size)
		return (lsrc);
	i = 0;
	while (i < size - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i++] = 0;
	return (lsrc);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	int		res_len;
	char	*res;

	if (!s2)
		return (s1);
	if (s1)
		res_len = -~(ft_strlen(s1) + ft_linelen(s2));
	else
		res_len = -~ft_linelen(s2);
	res = malloc(res_len * sizeof(char));
	if (!res)
		return (0);
	if (s1)
		ft_strlcpy(res, s1, res_len);
	else
		res[0] = 0;
	ft_strlcat(res, s2, res_len);
	free(s1);
	return (res);
}
