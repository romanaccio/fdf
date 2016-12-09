/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:16:56 by ajouanna          #+#    #+#             */
/*   Updated: 2016/11/08 16:18:04 by ajouanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putendl(char const *s)
{
	int		l;
	char	c;

	if (s)
	{
		l = ft_strlen(s);
		write(1, s, l);
		c = '\n';
		write(1, &c, 1);
	}
}
