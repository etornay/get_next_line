/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:08:09 by etornay-          #+#    #+#             */
/*   Updated: 2023/07/20 16:17:12 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_calloc(size_t num, size_t size)
{
	size_t	total_size;
	char	*dest;
	size_t	t;

	total_size = num * size;
	dest = (char *)malloc(total_size);
	if (dest == NULL)
		return (NULL);
	t = 0;
	while (t < total_size)
	{
		dest[t] = '\0';
		t++;
	}
	return (dest);
}

int	ft_strchr(const char *s, char c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		s1_len;
	int		i;

	if (s1 == NULL)
	{
		s1 = ft_calloc(1, sizeof(char));
		if (s1 == NULL)
			return (free(s1), s1 = NULL, NULL);
	}
	if (s2 == NULL)
		return (free(s1), s1 = NULL, NULL);
	s1_len = ft_strlen(s1);
	s3 = ft_calloc(s1_len + ft_strlen(s2) + 1, sizeof(char));
	if (s3 == NULL)
		return (free(s1), s1 = NULL, NULL);
	i = -1;
	while (s1[++i] != '\0')
		s3[i] = s1[i];
	i = -1;
	while (s2[++i] != '\0')
		s3[s1_len + i] = s2[i];
	s3[s1_len + i] = '\0';
	return (free(s1), s3);
}
/* #include <stdio.h>

int	main(void)
{
	char	*s3;

	s3 = ft_strjoin("Hola\n", "amigo");
	print("%s", s3);
}*/