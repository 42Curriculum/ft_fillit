/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctwords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 18:12:45 by jjosephi          #+#    #+#             */
/*   Updated: 2019/10/02 11:03:23 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ctwords(const char *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (s[i] != c)
		count++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			count++;
		i++;
	}
	return (count);
}
