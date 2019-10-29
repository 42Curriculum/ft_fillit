/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff_we_need.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:55:17 by jjosephi          #+#    #+#             */
/*   Updated: 2019/10/28 20:28:07 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*new_board(int size, t_board **b)
{
	int		i;
	char	*str;

	i = 0;
	free((*b)->value);
	str = ft_strnew(size * size);
	while (i < size * size)
	{
		str[i] = '.';
		i++;
	}
	str[i] = '\0';
	return (str);
}

int		p_count(int *str)
{
	int i;

	i = 0;
	while (str[i] != -1)
	{
		i++;
	}
	return (i);
}

void	print_n_free(t_board **b)
{
	int i;

	i = 0;
	while ((*b)->value[i])
	{
		if (i % (*b)->size == 0 && i > 0)
			ft_putchar('\n');
		ft_putchar((*b)->value[i]);
		i++;
	}
	free((*b)->value);
	free(*b);
}

int		falloc(int flag, char **input, char **line, int *pn)
{
	if (flag == 1)
	{
		free(*line);
		free(*input);
		*input = ft_strnew(0);
		*pn += 1;
		return (0);
	}
	else if (flag == 0)
	{
		*input = ft_strnew(0);
		*line = ft_strnew(0);
		*pn = 0;
		return (0);
	}
	else
	{
		free(*line);
		free(*input);
		return (1);
	}
}

char	*ft_strfjoin(char **s1, char const *s2)
{
	size_t	len;
	char	*str;
	char	*temp;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(*s1) + ft_strlen(s2) + 1;
	if (!(str = ft_memalloc(len)))
		return (NULL);
	str = ft_strcpy(str, *s1);
	free(*s1);
	str = ft_strcat(str, s2);
	temp = str;
	str = ft_strjoin(str, "\n");
	free(temp);
	return (str);
}
